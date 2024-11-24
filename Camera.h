#pragma once
#include <memory>
#include "Transform.h"
#include <SFML/Graphics.hpp>

class Camera
{
public:
	Camera();
	Camera(sf::RenderWindow& _renderWindow);
	Camera(sf::RenderWindow& _renderWindow, std::shared_ptr<Transform> _transform);
	void ResizeWindow();

	void SetRenderWindow(sf::RenderWindow& renderWin);
	void Move(float deltaTime);
	void Scale(float deltaTime);
public:
	operator bool() const
	{
		return renderWindow != nullptr && transform != nullptr;
	}
private:
	std::shared_ptr<Transform> transform;
	sf::RenderWindow* renderWindow; //Only use with references for safety
	sf::View view;
	float moveSpeed = 1000.0f;
};