#pragma once
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "Camera.h"
#include "UICamera.h"
#include "Time.h"

class Renderable;

namespace Renderer
{
	void Configure(sf::VideoMode mode, const std::string& windowName);
	void AddDrawable(const std::shared_ptr<Renderable>& renderable);
	void AddUIDrawable(const std::shared_ptr<Renderable>& renderable);
	void RemoveDrawable(const std::shared_ptr<Renderable>& renderable);
	void RemoveUIDrawable(const std::shared_ptr<Renderable>& renderable);
	void Clear();
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
	virtual void MakeUI() { isUI = true; }
	virtual void MakeWorld() { isUI = false; }
protected:
	bool isUI = false;
};