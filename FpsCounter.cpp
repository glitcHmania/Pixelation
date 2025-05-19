#include "FpsCounter.h"

FpsCounter::FpsCounter(std::string UID)
	: GameObject(UID)
{
}

void FpsCounter::Start()
{
    transform->SetLocalPosition(0.0f, -0.0f);
    textRenderer = AddComponent<TextRenderer>();
    textRenderer->MakeUI();

    textRenderer->SetFont(AssetLoader::GetFont("roboto.ttf"));
	textRenderer->SetSize(fontSize);
	textRenderer->SetFillColor(sf::Color(255, 0, 255));
	textRenderer->SetBorderColor(sf::Color(0, 0, 0));
    (*textRenderer)("INIT");
}

void FpsCounter::Update()
{
    (*textRenderer)("" + std::to_string((int)Time::FPS()) + " : " + std::to_string((float)1/Time::FPS()) + "ms");
}
