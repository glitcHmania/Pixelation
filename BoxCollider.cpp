#include "BoxCollider.h"
#include "Transform.h"

BoxCollider::BoxCollider()
    : size(1.0f, 1.0f) // or whatever default you want
{
    float halfExt[2] = { size.x / 2.0f, size.y / 2.0f };
    sf::Vector2f axes[2] = { {1.0f, 0.0f}, {0.0f, 1.0f} };
    rect = Geometry::DynamicRect({ 0, 0 }, halfExt, axes);
}

BoxCollider::BoxCollider(sf::Vector2f size)
    : size(size)
{
    float extents[2] = { size.x / 2.0f, size.y / 2.0f };
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
    sf::Vector2f scaledSize = { size.x * scale.x, size.y * scale.y };

    float halfExt[2] = { scaledSize.x / 2.0f, scaledSize.y / 2.0f };
    sf::Vector2f axes[2] = {
        transform->GetLocalAxis(0),
        transform->GetLocalAxis(1)
    };

    rect.Update(halfExt, transform->GetLocalPosition(), axes);
}


void BoxCollider::SetSize(const sf::Vector2f& newSize)
{
    size = newSize;

    if (transform)
    {
        float halfExt[2] = { size.x / 2.0f, size.y / 2.0f };
        sf::Vector2f axes[2] = {
            transform->GetLocalAxis(0),
            transform->GetLocalAxis(1)
        };

        rect.Update(halfExt, transform->GetLocalPosition(), axes);
    }
}


Geometry::Shape* BoxCollider::GetShape()
{
    return &rect;
}

bool BoxCollider::Intersects(const Collider* other) const
{
    auto otherRect = dynamic_cast<const BoxCollider*>(other);
    if (!otherRect) return false;

    return rect.Intersects(otherRect->rect);
}
