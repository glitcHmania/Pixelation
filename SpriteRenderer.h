#pragma once
#include "Transform.h"
#include "Component.h"
#include <SFML/Graphics.hpp>
#include "GameObject.h"


class SpriteRenderer : public Component, public sf::Drawable
{
public:
	SpriteRenderer();
	SpriteRenderer(const SpriteRenderer & rH) = delete;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void Update() override {};
	void Construct() override;
	void SetTexture(std::unique_ptr<sf::Texture> tx);
	sf::Texture& GetTexture()
	{ 
		return *texture; 
	}

private:
	std::unique_ptr<sf::Texture> texture;
	std::shared_ptr<Transform> transform;
	sf::VertexArray vertices;
	std::unique_ptr<sf::RenderStates> state;
};