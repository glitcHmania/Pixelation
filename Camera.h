#pragma once
#include <memory>
#include "Transform.h"
#include <SFML/Graphics.hpp>
#include "Window.h"

class Camera
{
public:
	Camera() = default;
	Camera(std::shared_ptr<sf::RenderWindow> _renderWindow);
	Camera(std::shared_ptr<sf::RenderWindow> _renderWindow, std::shared_ptr<Transform> _transform);

	void SetWindow(Window& win);
	void Move(float deltaTime);
public:
	operator bool() const
	{
		return renderWindow != nullptr && transform != nullptr;
	}
private:
	std::shared_ptr<Transform> transform;
	std::shared_ptr<sf::RenderWindow> renderWindow;
	sf::View view;
	float speed = 1000.0f;
};