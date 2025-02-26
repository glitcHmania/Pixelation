#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "Camera.h"
#include "Time.h"
#include "Renderer.h"
#include "ObjectManager.h"
#include "Events.h"
#include "EventDispatcher.h"

class Game
{
public:
	Game(const sf::Vector2<unsigned int>& resolution, const std::string& windowName = "Pixelation");

	void HandleSFMLEvents();
	void Loop();
	void Stop();

private:
	sf::Event eventHnd;
};
