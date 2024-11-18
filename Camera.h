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
	void Move(sf::Keyboard::Key pressedKey);
private:
	std::shared_ptr<Transform> transform;
	sf::RenderWindow* renderWindow;
	std::unique_ptr<sf::View> view;
};