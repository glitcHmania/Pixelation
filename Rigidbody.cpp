#include "Rigidbody.h"

Rigidbody::Rigidbody()
{
    
    velocity = { 0.0f, 0.0f };
    accumulatedForces = { 0.0f, 0.0f };
}

void Rigidbody::Configure()
{
    collider = owner->GetComponent<BoxCollider>().get();
	// Initialize the tracker with a minimum period of maximum deltaTime or selected value
    tracker = Time::RequestTracker(std::max(1.0f/120.0f, 0.0115f)).get();
}

void Rigidbody::Update(float deltaTime)
{
    while (tracker->Check())
    {
        //TimeStep
        deltaTime = 0.03f;
        if (isKinematic || mass <= 0.0f || !transform)
            return;

        sf::Vector2f normVel = -velocity.normalize();

        accumulatedForces = accumulatedForces + (normVel * mass * drag);

        if (useGravity)
            accumulatedForces = accumulatedForces + (gravity + (normVel * drag)) * mass;

        sf::Vector2f acceleration = accumulatedForces / mass;
        sf::Vector2f dV = acceleration * deltaTime;
        sf::Vector2f distance = ((velocity + dV * 2.0f) / 2.0f) * deltaTime;
        transform->Translate(distance);
        velocity = velocity + dV;

        accumulatedForces = { 0.0f, 0.0f };

        if (!collider)
            return;

        // Collision detection with all other objects
        ObjectManager& objMgr = ObjectManager::GetInstance();

        int count = ObjectManager::GetInstance().GetObjectCount();
        for (int i = 0; i < count; ++i)
        {
            auto other = objMgr.Get(i);
            if (!other || other.get() == owner)
                continue;

            auto otherCollider = other->GetComponent<BoxCollider>();
            if (!otherCollider)
                continue;

            auto intersecting = collider->Intersects(*otherCollider);

            if (intersecting.isHit)
            {
                bool trigger = collider->isTrigger || otherCollider->isTrigger;

                if (!trigger)
                {
                    sf::Vector2f dist = other->transform->GetLocalPosition() - transform->GetLocalPosition();
                    float neg = std::signbit(dist.x * intersecting.axis.x + dist.y * intersecting.axis.y) == true ? -1.0f : 1.0f;
                    float amount = intersecting.axis.x * velocity.x + intersecting.axis.y * velocity.y;
					float velsq = (velocity.x * velocity.x + velocity.y * velocity.y);
                    if ((amount)*neg > 0)
                    {
                        transform->Translate(intersecting.penetration);
                        sf::Vector2f force = -((mass * intersecting.axis * amount * (2.0f - drag)) / deltaTime);
                        accumulatedForces += force;
                    }
                }
            }
        }
    }
}

void Rigidbody::ApplyForce(const sf::Vector2f& force)
{
    accumulatedForces += force;
}

void Rigidbody::SetVelocity(const sf::Vector2f& vel)
{
    velocity = vel;
}

sf::Vector2f Rigidbody::GetVelocity() const
{
    return velocity;
}

void Rigidbody::SetMass(float m)
{
    mass = std::max(0.01f, m); // prevent instability
}

float Rigidbody::GetMass() const
{
    return mass;
}
