#pragma once
#include "GameObject.h"

class SpriteRenderer : public Renderable
{
public:
	SpriteRenderer();
	SpriteRenderer(const SpriteRenderer & rH) = delete;
	void Configure() override;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void SetTexture(std::unique_ptr<sf::Texture> tx);
	sf::Texture& GetTexture()
	{ 
		return *texture; 
	}

private:
	std::unique_ptr<sf::Texture> texture;
	sf::VertexArray vertices;
	std::unique_ptr<sf::RenderStates> state;
};