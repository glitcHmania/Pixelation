#include "AssetLoader.h"

namespace fs = std::filesystem;

namespace AssetLoader
{
	namespace
	{
		std::vector<std::filesystem::path> assetPaths;
		std::filesystem::path GetFilePath(std::string fileName)
		{
			for (fs::path& path : assetPaths)
			{
				if (path.filename() == fileName)
				{
					return path;
				}
			}
			return "";
		}
	}

	void ChangePath(std::string dir)
	{
		assetPaths.clear();
		for (const auto& entry : fs::recursive_directory_iterator(dir))
		{
			if (entry.is_regular_file() && !entry.path().extension().empty())
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
	}
	std::unique_ptr<sf::Texture> GetTexture(std::string imageName)
	{
		std::unique_ptr<sf::Texture> _texture;
		std::filesystem::path path = GetFilePath(imageName);
		_texture = std::make_unique<sf::Texture>();

		if (path.empty())
		{
			throw("Couldn't locate the image.");
		}
		if (!_texture->loadFromFile(path.string()))
		{
			throw("File is corrupted or can't be loaded");
		}

		return std::move(_texture);
	}

	std::unique_ptr<sf::Font> GetFont(std::string fontName)
	{
		std::unique_ptr<sf::Font> font;
		std::filesystem::path path = GetFilePath(fontName);
		font = std::make_unique<sf::Font>();

		if (path.empty())
		{
			throw("Couldn't locate the image.");
		}
		if (!font->loadFromFile(path.string()))
		{
			throw("File is corrupted or can't be loaded");
		}

		return std::move(font);
	}

}





