#pragma once
#include <SFML/System/Vector2.hpp>

struct Rect
{
public:
    Rect(sf::Vector2f position, sf::Vector2f size);

    // Check if this rectangle intersects with another
    bool intersects(const Rect& other) const;

     //Check if a point is inside the rectangle
    bool contains(sf::Vector2f point) const;
   
public:
	sf::Vector2f topLeft, bottomRight;
};