#include "Rectangle.h"

Rectangle::Rectangle(Transform* tf, float width, float height)
    :
    transform(tf),
    width(width),
    height(height)
{
}

bool Rectangle::IsCollidingWith(Transform* tf) const
{
    auto target = tf->GetLocalPosition();
    auto source = transform->GetLocalPosition();

    return target.x > (source.x - width / 2) && target.x < (source.x + width / 2) &&
        target.y >(source.y - height / 2) && target.y < (source.y + height / 2);
}

bool Rectangle::IsCollidingWith(Rectangle& rect) const
{
    auto target = rect.transform->GetLocalPosition();
	auto source = transform->GetLocalPosition();

	return target.x > (source.x - width / 2) && target.x < (source.x + width / 2) &&
		target.y >(source.y - height / 2) && target.y < (source.y + height / 2);
}

bool Rectangle::IsInBounds()
{
    auto source = transform->GetLocalPosition();
    auto bounds = Renderer::GetBounds();

    return source.x - width / 2 > 0.0f &&
        source.x + width / 2 < bounds.x &&
        source.y - height / 2 > 0.0f &&
        source.y + height / 2 < bounds.y;
}

bool Rectangle::IsInBounds(sf::Vector2f vec)
{
    auto source = transform->GetLocalPosition();
    auto bounds = Renderer::GetBounds();

    return source.x + vec.x - width / 2 > 0.0f &&
        source.x + vec.x + width / 2 < bounds.x &&
        source.y + vec.y - height / 2 > 0.0f &&
        source.y + vec.y + height / 2 < bounds.y;
}
