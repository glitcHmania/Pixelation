#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "Camera.h"
#include "Time.h"

class Renderer
{
public:
	Renderer() = default;
	Renderer(const std::shared_ptr<sf::RenderWindow>& renderWindow);

	template<typename T>
	void AddDrawable(const std::shared_ptr<T>& drawable)
	{
		static_assert(std::is_base_of<sf::Drawable, T>::value, "Tried to push an undrawable object to the draw queue!");
		queue.push_back(drawable);
	}
	void RemoveDrawable(int index);
	void CreateCamera();
	void RemoveCamera(int index);
	void SetMainCamera(const Camera& camera);
	void Update();

private:
	std::vector<std::shared_ptr<sf::Drawable>> queue;
	std::shared_ptr<sf::RenderWindow> renderWindow;
	std::vector<Camera> cameras;
	Camera mainCamera;
};

