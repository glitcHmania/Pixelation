#include "Rigidbody.h"
#include "Transform.h"
#include "Time.h"
#include "Gameobject.h"
#include "ObjectManager.h"

Rigidbody::Rigidbody()
{
    velocity = { 0.0f, 0.0f };
    accumulatedForces = { 0.0f, 0.0f };
}

void Rigidbody::Configure()
{
    collider = owner->GetComponentByBase<Collider>().get();
}


void Rigidbody::Update(float deltaTime)
{
    if (isKinematic || mass <= 0.0f || !transform)
        return;

    if (useGravity)
        ApplyForce(gravity * mass);

    sf::Vector2f acceleration = accumulatedForces / mass;
    velocity += acceleration * deltaTime;

    velocity -= velocity * drag * deltaTime;

    transform->Translate(velocity * deltaTime);

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

        auto otherCollider = other->GetComponentByBase<Collider>();
        if (!otherCollider)
            continue;

        bool intersecting = collider->Intersects(otherCollider.get());

        if (intersecting)
        {
            std::cout << "Collision detected between " << owner->GetUID()
                << " and " << other->GetUID() << "\n";

            bool trigger = collider->isTrigger || otherCollider->isTrigger;

            // Dispatch collision event immediately
            EventDispatcher::GetInstance().DispatchImmediate(
                CollisionEvent(owner, other.get(), trigger)
            );

            if (!trigger)
            {
                // Simple collision resolution: reverse velocity and move back
                velocity = -velocity;
                transform->Translate(velocity * deltaTime);
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
