#pragma once
#include <memory>
#include <SFML/Graphics.hpp>

class UICamera
{
public:
	UICamera();
	UICamera(sf::RenderWindow& _renderWindow);
	void SetFocus();
	void SetRenderWindow(sf::RenderWindow& renderWin);
	void ResizeWindow();
public:
	operator bool() const
	{
		return renderWindow != nullptr;
	}
private:
	sf::RenderWindow* renderWindow; //Only use with references for safety
	sf::View view;
};