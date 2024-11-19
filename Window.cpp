#include "Window.h"

Window::Window(sf::Vector2<unsigned int> resolution = { 800,600 }, const std::string windowName = "My Game")
	:
	eventHnd(sf::Event())
{
	window = std::make_shared<sf::RenderWindow>(sf::VideoMode(resolution.x, resolution.y), windowName);
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
		}

		if (camera)
		{
			camera->Move();
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

std::shared_ptr<sf::RenderWindow> Window::GetRenderWindow()
{
	return window;
}

void Window::SetCamera(std::shared_ptr<Camera> cam)
{
	camera = cam;
}
