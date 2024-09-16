#pragma once
#include <SFML/Graphics.hpp>
#include <filesystem>
#include <assert.h>


class AssetLoader
{
public:
	AssetLoader();
	AssetLoader(std::string dir);
	void ChangePath(std::string dir);
	void FillTextureFromImage(std::string imageName, sf::Texture& texture);


private:
	std::filesystem::path GetFilePath(std::string fileName);
private:
	std::vector<std::filesystem::path> assetPaths;
};