#pragma once
#include "Component.h"
#include <SFML/System/Vector2.hpp>
#include <cmath>
#include <vector>
#include <stdexcept>

class Transform : public Component
{
public:
	Transform() 
	{
		position = sf::Vector2f(0.0f, 0.0f);
		rotation = 0;
		scale = sf::Vector2f(150.f, 80.0f);
	};

	Transform(sf::Vector2f _position, float _rotation, sf::Vector2f _scale)
		:
		position(_position),
		rotation(_rotation),
		scale(_scale)
	{
	}

	void Construct() override {};

	void Update() override;

	void Scale(sf::Vector2f scaleFactor);

	void Rotate(float radian);

	void Translate(sf::Vector2f delta);
	void Translate(float x, float y);

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
	void SetLocalPosition(float x, float y);
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

