#include "Renderer.h"

namespace Renderer
{
	namespace 
	{
		std::unordered_map<std::string, std::shared_ptr<Renderable>> queue;
		std::unordered_map<std::string, std::shared_ptr<Renderable>> uiQueue;
		std::vector<Camera> cameras;
		Camera mainCamera;
		UICamera uiCamera;
		std::unique_ptr<sf::RenderWindow> renderWindow;
	}

	void Configure(sf::VideoMode mode, const std::string& windowName)
	{
		renderWindow = std::make_unique<sf::RenderWindow>(mode, windowName);
		uiCamera.SetRenderWindow(*renderWindow);
	}

	void Renderer::Update()
	{
		renderWindow->clear();

		if (mainCamera)
		{
			mainCamera.Update(Time::GetDeltatime());
			for (const auto& drawable : queue)
			{
				renderWindow->draw(*(drawable.second));
			}
		}
		if (uiCamera)
		{
			uiCamera.SetFocus();
			for (const auto& drawable : uiQueue)
			{
				renderWindow->draw(*(drawable.second));
			}
		}
		
		renderWindow->display();
	}

	sf::Vector2u GetBounds()
	{
		return renderWindow->getSize();
	}

	void Renderer::ResizeWindow()
	{
		if (mainCamera)
		{
			mainCamera.ResizeWindow();
		}
		if (uiCamera)
		{
			uiCamera.ResizeWindow();
		}
	}

	sf::RenderWindow& Renderer::GetWindow()
	{
		return *renderWindow;
	}

	void Renderer::AddDrawable(const std::shared_ptr<Renderable>& renderable)
	{
		queue[renderable->GetID()] = renderable;
	}

	void AddUIDrawable(const std::shared_ptr<Renderable>& renderable)
	{
		uiQueue[renderable->GetID()] = renderable;
	}

	void Renderer::RemoveDrawable(const std::shared_ptr<Renderable>& renderable)
	{
		queue.erase(renderable->GetID());
	}

	void RemoveUIDrawable(const std::shared_ptr<Renderable>& renderable)
	{
		uiQueue.erase(renderable->GetID());
	}

	void Clear()
	{
		queue.clear();
		uiQueue.clear();
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




