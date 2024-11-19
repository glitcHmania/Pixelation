#include "Window.h"

Window::Window(sf::Vector2<unsigned int> resolution = { 800,600 }, const std::string windowName = "My Game")
	:
	eventHnd(sf::Event())
{
	window = std::make_unique<sf::RenderWindow>(sf::VideoMode(resolution.x, resolution.y), windowName);
}

void Window::Discard(int index)
{
	if (queue.size() > index)
	{
		queue.erase(queue.begin() + index);
	}
}

void Window::Show()
{
	while (window->isOpen())
	{
		while (window->pollEvent(eventHnd))
		{
			if (eventHnd.type == sf::Event::Closed)
			{
				window->close();
			}
			if(camera && eventHnd.type == sf::Event::KeyPressed)
			{
				camera->Move(eventHnd.key.code);
			}
		}

		window->clear();
		//Put an update loop before drawing
		for (int i = 0; i < queue.size(); i++)
		{
			//sf::Transform(1, 0, 200, 0, 1, 0, 0, 0, 1)
			window->draw(*queue[i]);
		}
		//Put an update loop after drawing
		window->display();
	}
}

sf::RenderWindow* Window::GetRenderWindow()
{
	return window.get();
}

void Window::SetCamera(Camera* cam)
{
		camera = cam;
}
