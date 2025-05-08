#include "Rect.h"

Rect::Rect(sf::Vector2f position, sf::Vector2f size)
{
	topLeft = sf::Vector2f(position.x-size.x/2,position.y + size.y/2);
	bottomRight = sf::Vector2f(position.x + size.x / 2, position.y - size.y / 2);
}

bool Rect::intersects(const Rect& other) const
{
    return (other.topLeft.x < bottomRight.x &&
        other.bottomRight.x > topLeft.x &&
        other.topLeft.y > bottomRight.y &&
        other.bottomRight.y < topLeft.y);
}

bool Rect::contains(sf::Vector2f point) const
{
    return(point.x >= topLeft.x &&
        point.x <= bottomRight.x &&
        point.y >= bottomRight.y &&
        point.y <= topLeft.y);
}
