#include "Geometry.h"
#define EPSILON 0.1f

namespace Geometry 
{
	Rect::Rect(sf::Vector2f position, sf::Vector2f size)
	{
		topLeft = sf::Vector2f(position.x - size.x / 2, position.y + size.y / 2);
		bottomRight = sf::Vector2f(position.x + size.x / 2, position.y - size.y / 2);
	}

	void Rect::Place(sf::Vector2f position)
	{
		sf::Vector2f translate = (position - topLeft);
		topLeft = topLeft + translate;
		bottomRight = bottomRight + translate;
	}

	bool Rect::Intersects(const Rect& other) const
	{
		return (other.topLeft.x < bottomRight.x &&
			other.bottomRight.x > topLeft.x &&
			other.topLeft.y > bottomRight.y &&
			other.bottomRight.y < topLeft.y);
	}

	bool Rect::Contains(sf::Vector2f point) const
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

}