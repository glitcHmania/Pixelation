#include "Game.h"

Game::Game(const sf::Vector2<unsigned int>& resolution, const std::string& windowName)
	:
	eventHnd(sf::Event())
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
		if( eventHnd.type == sf::Event::KeyPressed)
		{
			ObjectManager::Destroy(5);
		}
	}
}

void Game::Loop()
{
	ObjectManager::Start();
	while (Renderer::GetWindow().isOpen())
	{
		HandleSFMLEvents();
		Time::CalculateDeltaTime();

		//Updates
		Renderer::Update();
		ObjectManager::Update();
		EventDispatcher::GetInstance().ProcessQueuedEvents();
		//ObjectManager::ProcessDestroyed();
	}
}

void Game::Stop()
{
	Renderer::GetWindow().close();
	Renderer::Clear();
	ObjectManager::DestroyAll();
}
