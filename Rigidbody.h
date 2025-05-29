#pragma once
#include "Component.h"
#include <SFML/System/Vector2.hpp>
#include "Transform.h"
#include "Time.h"
#include "Gameobject.h"
#include "ObjectManager.h"
#include "BoxCollider.h"

class Rigidbody : public Component
{
public:
    Rigidbody();

    void Configure() override;
    void Update(float deltaTime) override;

    void ApplyForce(const sf::Vector2f& force);
    void SetVelocity(const sf::Vector2f& vel);
    sf::Vector2f GetVelocity() const;

    void SetMass(float m);
    float GetMass() const;

    bool isKinematic = false;
    bool useGravity = true;
    float drag = 0.15f;

private:
    sf::Vector2f velocity;
    sf::Vector2f accumulatedForces;
    float mass = 1.0f;
    const sf::Vector2f gravity = { 0.0f, -9.81f }; 
    BoxCollider* collider = nullptr;

	Time::TimeTracker* tracker = nullptr;
};
