#include "TextRenderer.h"

TextRenderer::TextRenderer()
{
	text = std::make_unique<sf::Text>();
	state = std::make_unique<sf::RenderStates>();

	text->setFillColor(sf::Color::White);
	text->setCharacterSize(150);
}

void TextRenderer::Configure()
{
	Renderer::AddDrawable(owner->GetComponent<TextRenderer>());
}

void TextRenderer::Destruct()
{
	if (isUI)
	{
		Renderer::RemoveUIDrawable(owner->GetComponent<TextRenderer>());
	}
	else 
	{
		Renderer::RemoveDrawable(owner->GetComponent<TextRenderer>());
	}
}

void TextRenderer::operator()(std::string _text)
{
	text->setString(_text);
}

void TextRenderer::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	state->transform = transform->GetSF();
	target.draw(*text, *state);
}

void TextRenderer::SetFont(std::shared_ptr<sf::Font> _font)
{
	font = _font;
	text->setFont(*font);
}

void TextRenderer::SetSize(unsigned int _size)
{
	text->setCharacterSize(_size);
}

void TextRenderer::SetFillColor(sf::Color color)
{
	text->setFillColor(color);
}

void TextRenderer::SetBorderColor(sf::Color color)
{
	text->setOutlineColor(color);
	text->setOutlineThickness(1);
}

void TextRenderer::MakeUI()
{
	isUI = true;
	auto temp = owner->GetComponent<TextRenderer>();
	Renderer::RemoveDrawable(temp);
	Renderer::AddUIDrawable(temp);
}

void TextRenderer::MakeWorld()
{
	isUI = false;
	auto temp = owner->GetComponent<TextRenderer>();
	Renderer::RemoveUIDrawable(temp);
	Renderer::AddDrawable(temp);
}