#pragma once
#include <memory>
#include "Transform.h"
#include <SFML/Graphics.hpp>

class Camera
{
public:
	Camera() = default;
	Camera(std::shared_ptr<sf::RenderWindow> _renderWindow);
	Camera(std::shared_ptr<sf::RenderWindow> _renderWindow, std::shared_ptr<Transform> _transform);

	void Move();
private:
	std::shared_ptr<Transform> transform;
	std::shared_ptr<sf::RenderWindow> renderWindow;
	sf::View view;
};