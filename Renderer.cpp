#include "Renderer.h"

namespace Renderer
{
	namespace 
	{
		std::vector<std::shared_ptr<Renderable>> queue;
		std::vector<Camera> cameras;
		Camera mainCamera;
		std::unique_ptr<sf::RenderWindow> renderWindow;
	}

	void Configure(sf::VideoMode mode, const std::string& windowName)
	{
		renderWindow = std::make_unique<sf::RenderWindow>(mode, windowName);
	}

	void Renderer::Update()
	{
		renderWindow->clear();

		//temp, is it really?
		if (mainCamera)
		{
			mainCamera.Move(Time::GetDeltatime());
			mainCamera.Scale(Time::GetDeltatime());
		}
		//temp, is it really?

		for (const auto& drawable : queue)
		{
			renderWindow->draw(*drawable);
		}
		renderWindow->display();
	}

	void Renderer::ResizeWindow()
	{
		if (mainCamera)
		{
			mainCamera.ResizeWindow();
		}
	}

	sf::RenderWindow& Renderer::GetWindow()
	{
		return *renderWindow;
	}

	void Renderer::AddDrawable(const std::shared_ptr<Renderable>& renderable)
	{
		queue.push_back(renderable);
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
		cameras.emplace_back(*renderWindow);
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
}




