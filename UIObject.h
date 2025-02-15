#pragma once
#include <variant>
#include "GameObject.h"
#include "ComponentIncluder.h"
#include "AssetLoader.h"
#include "Time.h"

class UIObject : public GameObject
{
public:

	UIObject(std::string UID);
	void Start() override;
	void Update() override;
	void Configure(Transform objectConfig, std::string rendererType);

private:
	sf::Color color = sf::Color::White;
	unsigned int fontSize = 24u;

	SpriteRenderer* SpriteRendererPointer;
	TextRenderer* TextRendererPointer;
	bool isSprite;
	//koþula göre renderer tipi deðiþeceðini için std::variant kullandýk
	std::variant<std::shared_ptr<SpriteRenderer>, std::shared_ptr<TextRenderer>> renderer;

	
};
