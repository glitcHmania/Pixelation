#pragma once
#include "GameObject.h"
#include "Renderable.h"

class TextRenderer : public Renderable
{
public:
	TextRenderer();
	TextRenderer(const TextRenderer& rH) = delete;
	void operator()(std::string _text);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void SetFont(std::unique_ptr<sf::Font> _font);
	sf::Text& GetText()
	{
		return *text;
	}

private:
	std::unique_ptr<sf::Text> text;
	std::unique_ptr<sf::RenderStates> state;
	std::unique_ptr<sf::Font> font;
};
