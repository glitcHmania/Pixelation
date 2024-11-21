#include "Window.h"

Window::Window(sf::Vector2<unsigned int> resolution = { 800,600 }, const std::string windowName = "My Game")
	:
	eventHnd(sf::Event())
{
	renderWindow = std::make_shared<sf::RenderWindow>(sf::VideoMode(resolution.x, resolution.y), windowName);
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
	while (renderWindow->isOpen())
	{
		while (renderWindow->pollEvent(eventHnd))
		{
			if (eventHnd.type == sf::Event::Closed)
			{
				renderWindow->close();
			}
		}

		//optional logic//
		Time::CalculateDeltaTime();
		if (camera)
		{
			camera->Move(Time::GetDeltatime());
		}
		//optional logic//


		renderWindow->clear();
		//Put an update loop before drawing
		for (int i = 0; i < queue.size(); i++)
		{
			//sf::Transform(1, 0, 200, 0, 1, 0, 0, 0, 1)
			renderWindow->draw(*queue[i]);
		}
		//Put an update loop after drawing
		renderWindow->display();
	}
}

std::shared_ptr<sf::RenderWindow> Window::GetRenderWindow()
{
	return renderWindow;
}

void Window::SetCamera(Camera& cam)
{
	camera = std::make_shared<Camera>(cam);
	camera->SetWindow(*this);
}
