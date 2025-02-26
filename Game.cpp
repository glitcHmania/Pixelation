#include "Game.h"
#include "EventDispatcher.h"

Game::Game(const sf::Vector2<unsigned int>& resolution, const std::string& windowName)
	:
	eventHnd(sf::Event()),
	objectManager(10001)
{
	Renderer::Configure(sf::VideoMode(resolution.x, resolution.y), windowName);
	Renderer::GetWindow().setFramerateLimit(165);
	EventDispatcher::GetInstance();
}

void Game::HandleSFMLEvents()
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
		HandleSFMLEvents();
		Time::CalculateDeltaTime();

		//Updates
		Renderer::Update();
		objectManager.Update();
		//objectManager.ProcessLateDestroyed();
		EventDispatcher::GetInstance().ProcessQueuedEvents();
		EventDispatcher::GetInstance().HandleSFML();
	}
}

void Game::Stop()
{
	Renderer::GetWindow().close();
	Renderer::Clear();
	objectManager.DestroyAll();
}
