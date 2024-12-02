#include "Game.h"

Game::Game(const sf::Vector2<unsigned int>& resolution, const std::string& windowName)
	:
	renderer(sf::VideoMode(resolution.x, resolution.y), windowName),
	eventHnd(sf::Event())
{
	renderer.GetWindow().setFramerateLimit(150);
}

void Game::HandleEvents()
{
	while (renderer.GetWindow().pollEvent(eventHnd))
	{
		if (eventHnd.type == sf::Event::Closed)
		{
			renderer.GetWindow().close();
		}
		if (eventHnd.type == sf::Event::Resized) 
		{
			renderer.ResizeWindow();	
		}
	}
}

void Game::Loop()
{
	while (renderer.GetWindow().isOpen())
	{
		HandleEvents();
		Time::CalculateDeltaTime();
		Time::PrintFPS();

		//Updates
		renderer.Update();
		ObjectManager::Update();
	}
}

Renderer& Game::GetRenderer()
{
	return renderer;
}
