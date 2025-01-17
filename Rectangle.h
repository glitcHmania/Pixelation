#pragma once
#include "ComponentIncluder.h"
#include "ObjectManager.h"
#include "Renderer.h"

class Rectangle
{
public:
	Rectangle() = delete;
	Rectangle(Transform* tf, float width, float height);
	bool IsCollidingWith(Transform* tf) const;
	bool IsCollidingWith(Rectangle& rect) const;
	bool IsInBounds();
	bool IsInBounds(sf::Vector2f vec);

	float width;
	float height;
	Transform* transform;
};