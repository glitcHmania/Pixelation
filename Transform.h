#pragma once
#include "Component.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Transform.hpp>
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
		scale = sf::Vector2f(1.0f, 1.0f);
	};

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
	void Translate(float x, float y);

	void SetLocalPosition(sf::Vector2f pos);
	void SetLocalPosition(float x, float y);
	void SetLocalRotation(float rot);
	void SetLocalScale(sf::Vector2f scl);

	sf::Vector2f GetLocalPosition() const;
	//std::pair<float, float> GetLocalPositionPair() const;

	float GetLocalRotation() const;

	sf::Vector2f GetLocalScale() const;
	//std::pair<float, float> GetLocalScalePair() const;

	float* GetMatrix();
	sf::Vector2f GetLocalAxis(int index) const;
	sf::Transform GetSF();

private:
	void Compose();

private:
	sf::Vector2f position;
	sf::Vector2f scale;

	float rotation;
	float matrix[9] = {0};
	bool matrixDirty = false;
	sf::Vector2f axes[2];

	//std::unique_ptr<TransformComponent> parent = nullptr;
	//std::vector<std::unique_ptr<TransformComponent>> children;
};

