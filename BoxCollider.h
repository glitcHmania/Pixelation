#pragma once
#include "Collider.h"

class BoxCollider : public Collider
{
public:
    BoxCollider();
    BoxCollider(sf::Vector2f size);

    void Configure() override;
    void Update(float deltaTime) override;
    void SetSize(const sf::Vector2f& newSize);

    Geometry::Shape* GetShape() override;
    bool Intersects(const Collider* other) const override;

private:
    Geometry::DynamicRect rect;
    sf::Vector2f size;
};
