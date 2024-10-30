#include "Transform_C.h"

void Transform_C::Update()
{
	std::logic_error("The method or operation is not implemented.");
}

void Transform_C::Scale(sf::Vector2f scaleFactor)
{
	scale.x *= scaleFactor.x;
	scale.y *= scaleFactor.y;
}
void Transform_C::Rotate(float radian)
{
	rotation += radian;
}

void Transform_C::Translate(sf::Vector2f delta)
{
	position += delta;
}

void Transform_C::SetLocalPosition(sf::Vector2f pos)
{
	position = pos;
}

sf::Vector2f Transform_C::GetLocalPosition() const
{
	return { position.x, position.y };
}

void Transform_C::SetLocalRotation(float rot)
{
	rotation = rot;
}

float Transform_C::GetLocalRotation() const
{
	return rotation;
}

void Transform_C::SetLocalScale(sf::Vector2f scl)
{
	scale = scl;
}

sf::Vector2f Transform_C::GetLocalScale() const
{
	return { scale.x, scale.y };
}

sf::Vector2f Transform_C::GetRightVector() const
{
	return sf::Vector2f(std::cos(rotation), std::sin(rotation));
}

sf::Vector2f Transform_C::GetUpVector() const
{
	return sf::Vector2f(-std::sin(rotation), std::cos(rotation));
}
