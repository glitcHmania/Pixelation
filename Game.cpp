#include "Game.h"

Game::Game(const sf::Vector2<unsigned int>& resolution, const std::string& windowName)
	:
	renderWindow(std::make_shared<sf::RenderWindow>(sf::VideoMode(resolution.x, resolution.y), windowName)),
	renderer(renderWindow)
{
	renderWindow->setFramerateLimit(60);
}

void Game::HandleEvents()
{
	while (renderWindow->pollEvent(eventHnd))
	{
		if (eventHnd.type == sf::Event::Closed)
		{
			renderWindow->close();
		}
		//...
	}
}

void Game::Loop()
{
	while (renderWindow->isOpen())
	{
		HandleEvents();
		Time::CalculateDeltaTime();

		//Updates
		renderer.Update();
		ObjectManager::Update();
	}
}

std::shared_ptr<sf::RenderWindow> Game::GetRenderWindow() const
{
	return renderWindow;
}

Renderer& Game::GetRenderer()
{
	return renderer;
}
