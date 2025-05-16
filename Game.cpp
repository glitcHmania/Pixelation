#include "Game.h"
#include "EventDispatcher.h"

Game::Game(const sf::Vector2<unsigned int>& resolution, const std::string& windowName)
	:
	eventHnd(sf::Event())
{
	Renderer::Configure(sf::VideoMode(resolution.x, resolution.y), windowName);
	//Renderer::GetWindow().setFramerateLimit(165);
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
	ObjectManager::GetInstance().Start();
	while (Renderer::GetWindow().isOpen())
	{
		HandleSFMLEvents();
		Time::CalculateDeltaTime();

		//Updates
		Renderer::Update();
		ObjectManager::GetInstance().Update();
		//objectManager.ProcessLateDestroyed();
		EventDispatcher::GetInstance().ProcessQueuedEvents();
	}
}

void Game::Stop()
{
	Renderer::GetWindow().close();
	Renderer::Clear();
	ObjectManager::GetInstance().DestroyAll();
}
