#pragma once
#include <SFML/Graphics.hpp>
#include <filesystem>
#include <unordered_map>
#include <iostream>

namespace AssetLoader
{	
	void LoadFromDir(std::string dir);
	std::shared_ptr<sf::Texture> GetTexture(std::string imageName);
	std::shared_ptr<sf::Font> GetFont(std::string fontName);
};