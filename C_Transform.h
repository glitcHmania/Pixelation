#pragma once
#include "Component.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
#include <utility>
#include <cmath>
#include <memory>
#include <vector>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

class Transform : public Component
{
public:

	Transform() = default;

	Transform(sf::Vector2f _position, float _rotation, sf::Vector2f _scale)
		:
		position(_position),
		rotation(_rotation),
		scale(_scale)
	{
	}

	void Scale(sf::Vector2f scaleFactor);

	void Rotate(float radian);

	void Translate(sf::Vector2f delta);

	//inline sf::Vector2f GetPosition() const
	//{
	//	if (parent)
	//	{
	//		auto parentPos = parent->GetPosition();
	//		return { position.x + parentPos.x, position.y + parentPos.y };
	//	}
	//	else
	//	{
	//		return { position.x, position.y };
	//	}
	//}

	void SetLocalPosition(sf::Vector2f pos);
	sf::Vector2f GetLocalPosition() const;

	//inline float GetRotation() const
	//{
	//	if (parent)
	//	{
	//		return rotation + parent->GetRotation();
	//	}
	//	else
	//	{
	//		return rotation;
	//	}
	//}
	void SetLocalRotation(float rot);
	float GetLocalRotation() const;

	void SetLocalScale(sf::Vector2f scl);
	sf::Vector2f GetLocalScale() const;

	//sf::Vector2f GetWorldScale() const
	//{
	//	if (parent)
	//	{
	//		return { scale.x * parent->scale.x, scale.y * parent->scale.y };
	//	}
	//	else
	//	{
	//		return { scale.x, scale.y };
	//	}
	//}

	sf::Vector2f GetRightVector() const;
	sf::Vector2f GetUpVector() const;

	//void AddChild(std::unique_ptr<TransformComponent> child)
	//{
	//	children.push_back(child);
	//	child->parent = std::make_unique<TransformComponent>(this);
	//}
	//void RemoveChild(std::unique_ptr<TransformComponent> child)
	//{
	//	children.erase(std::remove(children.begin(), children.end(), child), children.end());
	//	child->parent.release();
	//}
	//TransformComponent* GetParent() const
	//{
	//	return parent.get();
	//}

	//TransformComponent* GetChild(int index) const
	//{
	//	if (index < 0 || index >= children.size())
	//	{
	//		return nullptr;
	//	}
	//	return children[index].get();
	//}

private:
	sf::Vector2f position;
	sf::Vector2f scale;
	float rotation;

	//std::unique_ptr<TransformComponent> parent = nullptr;
	//std::vector<std::unique_ptr<TransformComponent>> children;
};

