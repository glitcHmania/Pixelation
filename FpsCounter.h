#pragma once
#include "GameObject.h"
#include "ComponentIncluder.h"
#include "AssetLoader.h"
#include "Time.h"

class FpsCounter : public GameObject 
{
public:
	FpsCounter(std::string UID);
	void Start() override;
	void Update() override;

private:
	sf::Color color = sf::Color::White;
	unsigned int fontSize = 24u;
	std::shared_ptr<TextRenderer> textRenderer;
};
