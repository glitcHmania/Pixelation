#pragma once
#include "GameObject.h"

class TextRenderer : public Renderable
{
public:
	TextRenderer();
	void Configure() override;
	void Destruct() override;
	void operator()(std::string _text);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void SetFont(std::shared_ptr<sf::Font> _font);
	void SetSize(unsigned int _size);
	sf::Text& GetText()
	{
		return *text;
	}

	void MakeUI() override;
	void MakeWorld() override;

private:
	std::unique_ptr<sf::Text> text;
	std::unique_ptr<sf::RenderStates> state;
	std::shared_ptr<sf::Font> font;
};
