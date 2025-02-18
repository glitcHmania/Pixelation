#include "Game.h"

Game::Game(const sf::Vector2<unsigned int>& resolution, const std::string& windowName)
	:
	eventHnd(sf::Event()),
	objectManager(10000)
{
	Renderer::Configure(sf::VideoMode(resolution.x, resolution.y), windowName);
	Renderer::GetWindow().setFramerateLimit(165);
}

void Game::HandleEvents()
{
	while (Renderer::GetWindow().pollEvent(eventHnd))
	{
		if (eventHnd.type == sf::Event::Closed)
		{
			Stop();
		}
		if (eventHnd.type == sf::Event::Resized)
		{
			Renderer::ResizeWindow();
		}
	}
}

void Game::Loop()
{
	objectManager.Start();
	while (Renderer::GetWindow().isOpen())
	{
		HandleEvents();
		Time::CalculateDeltaTime();

		//Updates
		Renderer::Update();
		objectManager.Update();
		objectManager.ProcessDestroyed();
	}
}

void Game::Stop()
{
	Renderer::GetWindow().close();
	Renderer::Clear();
	objectManager.DestroyAll();
}
