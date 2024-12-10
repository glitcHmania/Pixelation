#pragma once
#include <vector>
#include <string>
#include "Camera.h"
#include "Time.h"
#include <SFML/Graphics.hpp>

class Renderable;

namespace Renderer
{
	void Configure(sf::VideoMode mode, const std::string& windowName);
	void AddDrawable(const std::shared_ptr<Renderable>& renderable);
	void RemoveDrawable(int index);
	void CreateCamera();
	void RemoveCamera(int index);
	void SetMainCamera(const Camera& camera);
	void ResizeWindow();
	void Update();

	sf::RenderWindow& GetWindow();
};

class Renderable : public Component, public sf::Drawable
{
public:
	Renderable() = default;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
};