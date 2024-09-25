#pragma once
#include <SFML/Graphics.hpp>
#include <filesystem>


namespace AssetLoader
{
	void ChangePath(std::string dir);
	void FillTextureFromImage(std::string imageName, sf::Texture& texture);
};