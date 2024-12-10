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

void TextRenderer::operator()(std::string _text)
{
	text->setString(_text);
}

void TextRenderer::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	state->transform = transform->GetSF();
	target.draw(*text, *state);
}



void TextRenderer::SetFont(std::unique_ptr<sf::Font> _font)
{
	font = std::move(_font);
	text->setFont(*font);
}
