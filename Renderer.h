#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "Camera.h"
#include "Time.h"

class Renderer
{
public:
	Renderer() = delete;
	Renderer(sf::VideoMode mode, const std::string& windowName = "ProjectDream");

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
	void ResizeWindow();
	void Zoom(float delta);
	void Update();

	sf::RenderWindow& GetWindow();

private:
	std::vector<std::shared_ptr<sf::Drawable>> queue;

	std::vector<Camera> cameras;
	Camera mainCamera;

	std::unique_ptr<sf::RenderWindow> renderWindow;
};

