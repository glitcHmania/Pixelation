#pragma once
#include "GameObject.h"

class SpriteRenderer : public Renderable
{
public:
	SpriteRenderer();
	void Configure() override;
	void Destruct() override;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void SetTexture(std::unique_ptr<sf::Texture> tx);
	sf::Texture& GetTexture()
	{
		return *texture;
	}

	void MakeUI() override;
	void MakeWorld() override;

private:
	std::shared_ptr<sf::Texture> texture;
	sf::VertexArray vertices;
	std::unique_ptr<sf::RenderStates> state;
};