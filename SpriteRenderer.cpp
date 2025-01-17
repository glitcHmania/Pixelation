#include "SpriteRenderer.h"

SpriteRenderer::SpriteRenderer()
{
	texture = std::make_unique<sf::Texture>();
	state = std::make_unique<sf::RenderStates>();

	vertices = sf::VertexArray(sf::PrimitiveType::TriangleFan, 4u);
}

void SpriteRenderer::Configure()
{
	Renderer::AddDrawable(owner->GetComponent<SpriteRenderer>());
}

void SpriteRenderer::Destruct()
{
	if (isUI)
	{
		Renderer::RemoveUIDrawable(owner->GetComponent<SpriteRenderer>());
	}
	else
	{
		Renderer::RemoveDrawable(owner->GetComponent<SpriteRenderer>());
	}
}

void SpriteRenderer::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	state->transform = transform->GetSF();
	target.draw(vertices, *state);
}

void SpriteRenderer::SetTexture(std::unique_ptr<sf::Texture> tx)
{
	texture = std::move(tx);
	state->texture = texture.get();

	sf::Vector2u dim = texture->getSize();

	float halfWidth = dim.x * 0.5f;
	float halfHeight = dim.y * 0.5f;

	vertices[0].position = sf::Vector2f(-halfWidth, -halfHeight);
	vertices[1].position = sf::Vector2f(halfWidth, -halfHeight);
	vertices[2].position = sf::Vector2f(halfWidth, halfHeight);
	vertices[3].position = sf::Vector2f(-halfWidth, halfHeight);

	vertices[0].texCoords = sf::Vector2f(0.0f, 0.0f);
	vertices[1].texCoords = sf::Vector2f((float)dim.x, 0.0f);
	vertices[2].texCoords = sf::Vector2f((float)dim.x, (float)dim.y);
	vertices[3].texCoords = sf::Vector2f(0.0f, (float)dim.y);
}


//overloaded function to set texture with rectangle
void SpriteRenderer::SetTexture(std::unique_ptr<sf::Texture> tx, sf::IntRect rect)
{
	if (!tx || tx->getSize().x == 0 || tx->getSize().y == 0)
		return;

	if (!texture || texture.get() != tx.get())
	{
		texture = std::move(tx);
		state->texture = texture.get();
	}

	float halfWidth = rect.width * 0.5f;
	float halfHeight = rect.height * 0.5f;

	vertices[0].position = sf::Vector2f(-halfWidth, -halfHeight);
	vertices[1].position = sf::Vector2f(halfWidth, -halfHeight);
	vertices[2].position = sf::Vector2f(halfWidth, halfHeight);
	vertices[3].position = sf::Vector2f(-halfWidth, halfHeight);

	vertices[0].texCoords = sf::Vector2f((float)rect.left, (float)rect.top);
	vertices[1].texCoords = sf::Vector2f((float)(rect.left + rect.width), (float)rect.top);
	vertices[2].texCoords = sf::Vector2f((float)(rect.left + rect.width), (float)(rect.top + rect.height));
	vertices[3].texCoords = sf::Vector2f((float)rect.left, (float)(rect.top + rect.height));
}



void SpriteRenderer::MakeUI()
{
	isUI = true;
	auto temp = owner->GetComponent<SpriteRenderer>();
	Renderer::RemoveDrawable(temp);
	Renderer::AddUIDrawable(temp);
}

void SpriteRenderer::MakeWorld()
{
	isUI = false;
	auto temp = owner->GetComponent<SpriteRenderer>();
	Renderer::RemoveUIDrawable(temp);
	Renderer::AddDrawable(temp);
}
