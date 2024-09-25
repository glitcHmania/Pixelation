#pragma once
#include <SFML/Graphics.hpp>
#include <filesystem>


class AssetLoader
{
public:
	AssetLoader() = default;
	AssetLoader(std::string dir);
	void ChangePath(std::string dir);
	void FillTextureFromImage(std::string imageName, sf::Texture& texture);
private:
	std::filesystem::path GetFilePath(std::string fileName);

private:
	std::vector<std::filesystem::path> assetPaths;
};