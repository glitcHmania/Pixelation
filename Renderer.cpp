#include "Renderer.h"

Renderer::Renderer(sf::VideoMode mode, const std::string& windowName = "ProjectDream")
{
	renderWindow = std::make_unique<sf::RenderWindow>(mode, windowName);
}

void Renderer::Update()
{
	renderWindow->clear();

	//temp
	if(mainCamera)
	{
		mainCamera.Move(Time::GetDeltatime());
	}
	//temp

	for (const auto& drawable : queue)
	{
		renderWindow->draw(*drawable);
	}
	renderWindow->display();
}

sf::RenderWindow& Renderer::GetWindow()
{
	return *renderWindow;
}

void Renderer::RemoveDrawable(int index)
{
	if (queue.size() > index)
	{
		queue.erase(queue.begin() + index);
	}
}

void Renderer::CreateCamera()
{
	cameras.emplace_back(renderWindow);
	if (!mainCamera)
	{
		mainCamera = cameras.back();
	}
}

void Renderer::RemoveCamera(int index)
{
	if (cameras.size() > index && cameras.at(index) != mainCamera)
	{
		cameras.erase(cameras.begin() + index);
	}
}

void Renderer::SetMainCamera(const Camera& camera)
{
	mainCamera = camera;
}
