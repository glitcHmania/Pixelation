#pragma once
#include "Component.h"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"

class SpriteRenderer : public Component 
{
public:
	
private:
	sf::Sprite sprite;
	sf::Texture texture;
};