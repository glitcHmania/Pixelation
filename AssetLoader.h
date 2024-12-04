#pragma once
#include <SFML/Graphics.hpp>
#include <filesystem>

namespace AssetLoader
{
	void ChangePath(std::string dir);
	void FillTextureFromImage(std::string imageName, sf::Texture& texture);
	std::unique_ptr<sf::Texture> GetTexture(std::string imageName);
	std::unique_ptr<sf::Font> GetFont(std::string fontName);
};