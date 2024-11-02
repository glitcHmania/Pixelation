#include "SpriteRenderer.h"

SpriteRenderer::SpriteRenderer()
{
	texture = std::make_unique<sf::Texture>();
	state = std::make_unique<sf::RenderStates>();

	vertices = sf::VertexArray(sf::PrimitiveType::TriangleFan, 4u);
}

void SpriteRenderer::Construct()
{
	if (transform == nullptr)
	{
		transform = owner->GetComponent<Transform>();
		
		//Only for debugging, delete this after transform is configured
		sf::Vector2f s = transform->GetLocalScale();
		vertices[0].position = sf::Vector2f(0.0f, 0.0f);
		vertices[1].position = sf::Vector2f(s.x, 0.0f);
		vertices[2].position = sf::Vector2f(s.x, s.y);
		vertices[3].position = sf::Vector2f(0.0f, s.y);
		//Only for debugging, delete this after transform is configured
	}
}

void SpriteRenderer::SetTexture(std::unique_ptr<sf::Texture> tx)
{
	texture = std::move(tx);
	state->texture = texture.get();

	sf::Vector2u dim = texture->getSize();
	vertices[0].texCoords = sf::Vector2f(0.0f, 0.0f);
	vertices[1].texCoords = sf::Vector2f(dim.x, 0.0f);
	vertices[2].texCoords = sf::Vector2f(dim.x, dim.y);
	vertices[3].texCoords = sf::Vector2f(0.0f, dim.y);
}

void SpriteRenderer::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	//states.transform = transform->ConvertToSf();
	target.draw(vertices, *state);
}

