#pragma once
#include "Collider.h"
#include "Transform.h"

class BoxCollider : public Collider
{
public:
    BoxCollider();

    void Configure() override;
    void Update(float deltaTime) override;

    Geometry::Shape* GetShape() override;
    Geometry::HitInfo Intersects(const BoxCollider& other) const;

private:
    Geometry::DynamicRect rect;
};
