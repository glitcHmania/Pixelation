#include "BoxCollider.h"

BoxCollider::BoxCollider()
{
    sf::Vector2f scale = transform ? transform->GetLocalScale() : sf::Vector2f(1, 1);
    float extents[2] = { scale.x / 2.0f, scale.y / 2.0f };
    sf::Vector2f defaultAxes[2] = { {1.0f, 0.0f}, {0.0f, 1.0f} };
    rect = Geometry::DynamicRect(transform ? transform->GetLocalPosition() : sf::Vector2f(0, 0), extents, defaultAxes);
}

void BoxCollider::Configure()
{
    //sync rect with transform
    Update(0);
}

void BoxCollider::Update(float deltaTime)
{
    if (!transform) return;

    sf::Vector2f scale = transform->GetLocalScale();

    float halfExt[2] = { scale.x/2.0f, scale.y /2.0f};
    sf::Vector2f axes[2] = {
        transform->GetLocalAxis(0),
        transform->GetLocalAxis(1)
    };

    rect.Update(halfExt, transform->GetLocalPosition(), axes);
}

Geometry::Shape* BoxCollider::GetShape()
{
    return &rect;
}

Geometry::HitInfo BoxCollider::Intersects(const BoxCollider& other) const
{
    return rect.Intersects(other.rect);
}
