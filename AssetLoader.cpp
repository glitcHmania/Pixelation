#include "AssetLoader.h"

namespace fs = std::filesystem;

AssetLoader::AssetLoader(std::string dir)
{
	for (const auto& entry : fs::directory_iterator(dir)) 
	{
		if (!entry.path().extension().empty())
		{
			assetPaths.push_back(entry.path());
		}
	}
}

void AssetLoader::ChangePath(std::string dir)
{
	assetPaths.clear();
	for (const auto& entry : fs::directory_iterator(dir))
	{
		if (!entry.path().extension().empty())
		{
			assetPaths.push_back(entry.path());
		}
	}
}

void AssetLoader::FillTextureFromImage(std::string imageName, sf::Texture& texture)
{
	std::filesystem::path path = GetFilePath(imageName);
	
	if (path.empty())
	{
		throw("Couldn't locate the image.");
	}
	if (!texture.loadFromFile(path.string()))
	{
		throw("File is corrupted or can't be loaded");
	}
	return;
}

std::filesystem::path AssetLoader::GetFilePath(std::string fileName)
{
	for (fs::path& path : assetPaths)
	{
		if (path.filename() == fileName)
			return path;
	}
	return "";
}
