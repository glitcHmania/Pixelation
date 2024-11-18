#include "Transform.h"

void Transform::Update()
{
	std::logic_error("The method or operation is not implemented.");
}

void Transform::Scale(sf::Vector2f scaleFactor)
{
	scale.x *= scaleFactor.x;
	scale.y *= scaleFactor.y;
}

void Transform::Rotate(float radian)
{
	rotation += radian;
}

void Transform::Translate(sf::Vector2f delta)
{
	position += delta;
}

void Transform::Translate(float x, float y)
{
	position += sf::Vector2f(x, y);
}

void Transform::SetLocalPosition(sf::Vector2f pos)
{
	position = pos;
}

void Transform::SetLocalPosition(float x, float y)
{
	position = sf::Vector2f(x, y);
}

sf::Vector2f Transform::GetLocalPosition() const
{
	return { position.x, position.y };
}

void Transform::SetLocalRotation(float rot)
{
	rotation = rot;
}

float Transform::GetLocalRotation() const
{
	return rotation;
}

void Transform::SetLocalScale(sf::Vector2f scl)
{
	scale = scl;
}

sf::Vector2f Transform::GetLocalScale() const
{
	return { scale.x, scale.y };
}

sf::Vector2f Transform::GetRightVector() const
{
	return sf::Vector2f(std::cos(rotation), std::sin(rotation));
}

sf::Vector2f Transform::GetUpVector() const
{
	return sf::Vector2f(-std::sin(rotation), std::cos(rotation));
}
