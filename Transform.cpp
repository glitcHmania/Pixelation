#include "Transform.h"

void Transform::Update()
{
	std::logic_error("The method or operation is not implemented.");
}

void Transform::Scale(sf::Vector2f scaleFactor)
{
	scale.x *= scaleFactor.x;
	scale.y *= scaleFactor.y;
	Compose();
}

void Transform::Rotate(float radian)
{
	rotation += radian;
	Compose();
}

void Transform::Translate(sf::Vector2f delta)
{
	position += delta;
	Compose();
}

void Transform::Translate(float x, float y)
{
	position += sf::Vector2f(x, y);
	Compose();
}

void Transform::SetLocalPosition(sf::Vector2f pos)
{
	position = pos;
	Compose();
}

void Transform::SetLocalPosition(float x, float y)
{
	position = sf::Vector2f(x, y);
	Compose();
}

void Transform::SetLocalRotation(float rot)
{
	rotation = rot;
	Compose();
}

void Transform::SetLocalScale(sf::Vector2f scl)
{
	scale = scl;
	Compose();
}

sf::Vector2f Transform::GetLocalPosition() const
{
	return { position.x, position.y };
}

std::pair<float, float> Transform::GetLocalPositionPair() const
{
	return std::pair<float, float>(position.x, position.y);
}

float Transform::GetLocalRotation() const
{
	return rotation;
}

sf::Vector2f Transform::GetLocalScale() const
{
	return { scale.x, scale.y };
}

std::pair<float, float> Transform::GetLocalScalePair() const
{
	return std::pair<float, float>(scale.x, scale.y);
}

sf::Vector2f Transform::GetRightVector() const
{
	return sf::Vector2f(std::cos(rotation), std::sin(rotation));
}

sf::Vector2f Transform::GetUpVector() const
{
	return sf::Vector2f(-std::sin(rotation), std::cos(rotation));
}

void Transform::Compose()
{
	composite[0] = std::cos(rotation) * scale.x;
	composite[1] = -std::sin(rotation) * scale.y;
	composite[2] = position.x;

	composite[3] = std::sin(rotation) * scale.x;
	composite[4] = std::cos(rotation) * scale.y;
	composite[5] =  position.y;
	
	composite[6] = 0.0f;
	composite[7] = 0.0f;
	composite[8] = 1.0f;
}

const float* Transform::GetComposite() const
{
	return composite;
}

sf::Transform Transform::GetSf() const
{
	return sf::Transform(composite[0],composite[1],composite[2], composite[3], composite[4], composite[5], composite[6], composite[7], composite[8]);
}
