#include "AssetLoader.h"
namespace fs = std::filesystem;

namespace AssetLoader
{
	namespace
	{
		std::unordered_map<std::string ,std::shared_ptr<sf::Texture>> texturesMap;
		std::unordered_map<std::string, std::shared_ptr<sf::Font>> fontsMap;
		enum extensionType 
		{
			SPRITE,
			FONT,
			INVALID
		};

		int determineExtension(std::string extension) 
		{
			if (extension == ".png" || extension == ".jpg" || extension == ".bmp" || extension == ".webp" || extension == ".jpeg")
				return extensionType::SPRITE;

			else if (extension == ".ttf")
				return extensionType::FONT;

			std::cout << "File extension " << extension << " is not supported.";
			throw("File extension isn't supported.");
			return extensionType::INVALID;
		}

		void LoadFontFromDir(std::filesystem::path fontPath) 
		{
			std::shared_ptr<sf::Font> tempFont = std::make_unique<sf::Font>();
			tempFont->loadFromFile(fontPath.string());
			fontsMap[fontPath.filename().string()] = tempFont;
		}

		void LoadSpriteFromDir(std::filesystem::path spritePath)
		{
			std::shared_ptr<sf::Texture> tempTexture = std::make_unique<sf::Texture>();
			tempTexture->loadFromFile(spritePath.string());
			texturesMap[spritePath.filename().string()] = tempTexture;
		}
	}

	void AssetLoader::LoadFromDir(std::string dir) 
	{
		for (const auto& entry : fs::recursive_directory_iterator(dir)) 
		{
			if (entry.is_regular_file()) 
			{
				switch (determineExtension(entry.path().extension().string()))
				{
					case extensionType::FONT:
						LoadFontFromDir(entry.path());
						break;

					case extensionType::SPRITE:
						LoadSpriteFromDir(entry.path());
						break;

					default:
						break;
				}
			}
		}
	}

	std::shared_ptr<sf::Texture> GetTexture(std::string imageName)
	{
		if (texturesMap.find(imageName) == texturesMap.end()) 
		{
			throw("Image name not found.");
		}
		else 
		{
			return texturesMap[imageName];
		}
	}

	std::shared_ptr<sf::Font> GetFont(std::string fontName)
	{
		if (fontsMap.find(fontName) == fontsMap.end()) 
		{
			throw("Image name not found.");
		}
		else 
		{
			return fontsMap[fontName];
		}
	}
}





