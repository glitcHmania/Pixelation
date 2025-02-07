#include "Game.h"

Game::Game(const sf::Vector2<unsigned int>& resolution, const std::string& windowName)
	:
	eventHnd(sf::Event())
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
	ObjectManager::Start();
	while (Renderer::GetWindow().isOpen())
	{
		HandleEvents();
		Time::CalculateDeltaTime();

		//Updates
		Renderer::Update();
		ObjectManager::Update();
		ObjectManager::ProcessDestroyed();
	}
}

void Game::Stop()
{
	Renderer::GetWindow().close();
	Renderer::Clear();
	ObjectManager::DestroyAll();
}
