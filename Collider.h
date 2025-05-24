#pragma once
#include "Component.h"
#include "Geometry.h"

class Collider : public Component
{
public:
    bool isTrigger = false;

    virtual Geometry::Shape* GetShape() = 0;
    //virtual Geometry::HitInfo Intersects(const Collider* other) {};
};

