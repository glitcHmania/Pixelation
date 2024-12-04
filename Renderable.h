#pragma once
#include "Component.h"
#include <SFML/Graphics.hpp>


class Renderable : public Component, public sf::Drawable
{
public:
	Renderable() = default;
	Renderable(const Renderable& rH) = delete;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
};
