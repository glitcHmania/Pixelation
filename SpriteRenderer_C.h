#pragma once
#include "Transform_C.h"
#include "Component.h"
#include <SFML/Graphics.hpp>
#include "GameObject.h"


class SpriteRenderer_C : public Component, public sf::Drawable
{
public:
	SpriteRenderer_C();
	SpriteRenderer_C(const SpriteRenderer_C & rH) = delete;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void Update() override {};
	void Construct() override;
	void SetTexture(std::unique_ptr<sf::Texture> tx);
	void SetTexture(sf::Texture* tx);
	sf::Texture& GetTexture()
	{ 
		return *texture; 
	}

private:
	std::unique_ptr<sf::Texture> texture;
	std::shared_ptr<Transform_C> transform;
	sf::VertexArray vertices;
	std::unique_ptr<sf::RenderStates> state;
};