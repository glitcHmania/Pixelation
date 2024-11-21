#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "Camera.h"
#include "Time.h"
#include "Renderer.h"
#include "ObjectManager.h"

class Game
{
public:
	Game(const sf::Vector2<unsigned int>& resolution, const std::string& windowName = "ProjectDream");

	void HandleEvents();
	void Loop();
	std::shared_ptr<sf::RenderWindow> GetRenderWindow() const;
	Renderer& GetRenderer();

private:
	std::shared_ptr<sf::RenderWindow> renderWindow;
	Renderer renderer;
	sf::Event eventHnd;
};
