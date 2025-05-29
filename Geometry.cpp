#include "Geometry.h"
#define EPSILON 0.1f

namespace Geometry 
{
	StaticRect::StaticRect(sf::Vector2f position, sf::Vector2f size)
	{
		topLeft = sf::Vector2f(position.x - size.x / 2, position.y + size.y / 2);
		bottomRight = sf::Vector2f(position.x + size.x / 2, position.y - size.y / 2);
	}

	void StaticRect::Place(sf::Vector2f position)
	{
		sf::Vector2f translate = (position - topLeft);
		topLeft = topLeft + translate;
		bottomRight = bottomRight + translate;
	}

	bool StaticRect::Intersects(const StaticRect& other) const
	{
		return (other.topLeft.x < bottomRight.x &&
			other.bottomRight.x > topLeft.x &&
			other.topLeft.y > bottomRight.y &&
			other.bottomRight.y < topLeft.y);
	}

	bool StaticRect::Contains(sf::Vector2f point) const
	{
		return(point.x >= topLeft.x &&
			point.x <= bottomRight.x &&
			point.y >= bottomRight.y &&
			point.y <= topLeft.y);
	}


	Sphere::Sphere(sf::Vector2f center, float radius)
		:
		center(center),
		radius(radius)
	{
	}

	void Sphere::Place(sf::Vector2f position)
	{
		center = position;
	}

	bool Sphere::Intersects(const Sphere& other)
	{
		sf::Vector2f difference = other.center - center;
		float distance = difference.x * difference.x + difference.y * difference.y;
		return distance < (other.radius + radius) * (other.radius + radius);
	}

	bool Sphere::Contains(const sf::Vector2f point) const
	{
		sf::Vector2f difference = point - center;
		float distance = difference.x * difference.x + difference.y * difference.y;
		return distance < radius * radius;
	}


	Capsule::Capsule(sf::Vector2f start, sf::Vector2f end, float radius)
		:
		start(start),
		end(end),
		radius(radius)
	{
	}

	void Capsule::Place(sf::Vector2f position)
	{
		sf::Vector2f difference = position - start;
		start = difference + start;
		end = difference + end;
	}

	bool Capsule::Intersects(const Capsule& other)
	{
		// Compute (squared) distance between the inner structures of the capsules
		sf::Vector2f c1, c2;
		float dist2 = ClosestPtSegmentSegment(start, end,
			other.start, other.end, c1, c2);

		// If (squared) distance smaller than (squared) sum of radii, they collide
		float r = radius + other.radius;
		return dist2 <= r * r;
	}

	bool Capsule::Contains(const sf::Vector2f point) const
	{
		Capsule c(point, point, 0.0f);
		return c.Intersects(*this);
	}

	float Capsule::Clamp(float n, float min, float max)
	{
		if (n < min) return min;
		if (n > max) return max;
		return n;
	}

	float Capsule::ClosestPtSegmentSegment(sf::Vector2f p1, sf::Vector2f q1, sf::Vector2f p2, sf::Vector2f q2, sf::Vector2f& c1, sf::Vector2f& c2)
	{

		sf::Vector2f d1 = q1 - p1; // Direction vector of segment S1
		sf::Vector2f d2 = q2 - p2; // Direction vector of segment S2
		sf::Vector2f r = p1 - p2;
		float a = d1.x * d1.x + d1.y * d1.y;// Squared length of segment S1, always nonnegative
		float e = d2.x * d2.x + d2.y * d2.y; // Squared length of segment S2, always nonnegative
		float f =  d2.x* r.x + d2.y * r.y;
		float s,t;

		// Check if either or both segments degenerate into points
		if (a <= EPSILON && e <= EPSILON) 
		{
			// Both segments degenerate into points
			s = t = 0.0f;
			c1 = p1;
			c2 = p2;
			sf::Vector2f temp = c1 - c2;
			return  (temp.x * temp.x + temp.y * temp.y);
		}
		if (a <= EPSILON) 
		{
			// First segment degenerates into a point
			s = 0.0f;
			t = f / e; // s = 0 => t = (b*s + f) / e = f / e
			t = Clamp(t, 0.0f, 1.0f);
		}
		else
		{
			float c = d1.x * r.x + d1.y * r.y;
			if (e <= EPSILON) 
			{
				// Second segment degenerates into a point
				t = 0.0f;
				s = Clamp(-c / a, 0.0f, 1.0f); // t = 0 => s = (b*t - c) / a = -c / a
			}
			else
			{
				// The general nondegenerate case starts here
				float b = d1.x * d2.x + d1.y * d2.y;
				float denom = a * e - b * b; // Always nonnegative

				// If segments not parallel, compute closest point on L1 to L2 and
				// clamp to segment S1. Else pick arbitrary s (here 0)
				if (denom != 0.0f) {
					s = Clamp((b * f - c * e) / denom, 0.0f, 1.0f);
				}
				else s = 0.0f;

				// Compute point on L2 closest to S1(s) using
				// t = Dot((P1 + D1*s) - P2,D2) / Dot(D2,D2) = (b*s + f) / e
				float tnom = (b * s + f);

				// If t in [0,1] done. Else clamp t, recompute s for the new value
				// of t using s = Dot((P2 + D2*t) - P1,D1) / Dot(D1,D1)= (t*b - c) / a
				// and clamp s to [0, 1]
				if (tnom < 0.0f) 
				{
					t = 0.0f;
					s = Clamp(-c / a, 0.0f, 1.0f);
				}
				else if (tnom > e) 
				{
					t = 1.0f;
					s = Clamp((b - c) / a, 0.0f, 1.0f);
				}
				else 
				{
					t = tnom / e;
				}
			}
		}

		c1 = p1 + d1 * s;
		c2 = p2 + d2 * t;
		sf::Vector2f temp = c1 - c2;
		return temp.x * temp.x + temp.y * temp.y;
	}

	DynamicRect::DynamicRect(sf::Vector2f _center, float _halfExt[2], sf::Vector2f _axes[2])
		:
		center(_center)
	{
		halfExt[0] = _halfExt[0];
		halfExt[1] = _halfExt[1];
		localAxis[0] = _axes[0];
		localAxis[1] = _axes[1];
	}

	void DynamicRect::Update(float _halfExt[2], sf::Vector2f _center, sf::Vector2f axes[2])
	{
		halfExt[0] = _halfExt[0];
		halfExt[1] = _halfExt[1];
		center = _center;
		localAxis[0] = axes[0];
		localAxis[1] = axes[1];
	}

	void DynamicRect::Place(sf::Vector2f position)
	{
		center = position;
	}

	HitInfo DynamicRect::Intersects(const DynamicRect& other) const
	{
		float ra, rb;
		float R[2][2], absR[2][2];
		float distances[4];

		// Compute rotation matrix expressing b in a�s coordinate frame
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				R[i][j] = localAxis[i].x * other.localAxis[j].x + localAxis[i].y * other.localAxis[j].y;
			}
		}

		sf::Vector2f temp = other.center - center;
		// Compute translation vector t
		float t[2] = { temp.x, temp.y };

		// Bring translation into a�s coordinate frame
		t[0] = (localAxis[0].x * temp.x + localAxis[0].y * temp.y);
		t[1] = (localAxis[1].x * temp.x + localAxis[1].y * temp.y);

		// Compute common subexpressions.
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				absR[i][j] = std::abs(R[i][j]);

		// Test axes L = A0, L = A1
		for (int i = 0; i < 2; i++)
		{
			ra = halfExt[i];
			rb = other.halfExt[0] * absR[i][0] + other.halfExt[1] * absR[i][1];
			distances[i] = +ra +rb -std::abs(t[i]) ;
			if (distances[i] <= 0) return HitInfo(false, {0,0});
		}

		// Test axes L = B0, L = B1
		for (int i = 0; i < 2; i++)
		{
			ra = halfExt[0] * absR[0][i] + halfExt[1] * absR[1][i];
			rb = other.halfExt[i];
			distances[2 + i] = +ra + rb -std::abs(t[0] * R[0][i] + t[1] * R[1][i]) ;
			if (distances[2 + i]<=0) return HitInfo(false, { 0,0 });
		}

		float minValue = (float) INT_MAX;
		int inx = 0;
		sf::Vector2f resolution = { 0.0f, 0.0f };

		for (int i = 0; i < 4; ++i)
		{
			float a = distances[i] * distances[i];
			if (a < minValue)
			{
				minValue = a;
				inx = i;
			}
		}
		
		if (inx < 2)
		{
			resolution = distances[inx] * localAxis[inx] ;
			return HitInfo(true, resolution, localAxis[inx]);
		}
		else
		{
			resolution = distances[inx] * other.localAxis[inx - 2];
			return HitInfo(true, resolution, other.localAxis[inx - 2]);
		}
	}

	bool DynamicRect::Contains(const sf::Vector2f point) const
	{
		sf::Vector2f t = point - center;
		t = sf::Vector2f((localAxis[0].x * t.x + localAxis[0].y * t.y), (localAxis[1].x * t.x + localAxis[1].y * t.y));
		if (t.x > halfExt[0])
			return 0;
		if (t.y > halfExt[1])
			return 0;
		return 1;
	}

	Triangle::Triangle(sf::Vector2f _points[3])
	{
		for (int i = 0; i <3; i++)
			points[i] = _points[i];
	}
	void Triangle::Place(sf::Vector2f position)
	{
		sf::Vector2f difference = position - points[0];
		for (int i = 0; i < 3; i++)
		{
			points[i] = difference + points[i];
		}
	}
	bool Triangle::Contains(const sf::Vector2f point) const
	{
		float alpha = 0.0f, beta = 0.0f, theta = 0.0f;
		float denom = Cross(points[1] - points[0], points[2] - points[0]);
		if (denom != 0)
		{
			alpha = Cross(point - points[0], points[2] - points[0]) / denom;
			beta = Cross(points[1] - points[0], point - points[0]) / denom;
			theta = 1 - alpha - beta;

			if (alpha < 0.0f || alpha > 1.0f)
				return false;
			if (beta < 0.0f || beta > 1.0f)
				return false;
			if (theta < 0.0f || theta > 1.0f)
				return false;

			return true;
		}
		return false;
	}
	Ray::Ray(sf::Vector2f _start, sf::Vector2f direction, float length)
		:
		start(_start)
	{
		end = _start + (direction * length);
	}
	Ray::Ray(sf::Vector2f _start, sf::Vector2f _end)
		:
		start(_start),
		end(_end)
	{
	}
	HitInfo Ray::Intersects(Triangle& other)
	{
		sf::Vector2f D = end - start;
		sf::Vector2f E1 = other.points[1] - other.points[0];
		sf::Vector2f E2 = other.points[2] - other.points[0];
		sf::Vector2f Q = start - other.points[0];

		float det = E1.x * E2.y - E1.y * E2.x;
		if (std::abs(det) < 1e-6f)
			return HitInfo(false); // Degenerate triangle

		float invDet = 1.0f / det;

		float u = (Q.x * E2.y - Q.y * E2.x) * invDet;
		float v = (E1.x * Q.y - E1.y * Q.x) * invDet;

		if (u < 0 || v < 0 || (u + v) > 1)
			return HitInfo(false);

		float tDet = (E1.x * D.y - E1.y * D.x);
		if (std::abs(tDet) < 1e-6f)
			return HitInfo(false); // Ray parallel

		float t = (Q.x * D.y - Q.y * D.x) / tDet;
		if (t < 0)
			return HitInfo(false);

		//Axis is NOT normalized
		return HitInfo(true , start + D*t , D);
	}
}