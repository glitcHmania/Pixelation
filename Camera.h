#pragma once
#include <memory>
#include "Transform.h"
#include <SFML/Graphics.hpp>

class Camera
{
public:
	Camera() = default;
	Camera(sf::RenderWindow* _renderWindow);
	Camera(sf::RenderWindow* _renderWindow, std::shared_ptr<Transform> _transform);

	void Move();
private:
	std::shared_ptr<Transform> transform;
	sf::RenderWindow* renderWindow = nullptr;
	std::unique_ptr<sf::View> view;
};