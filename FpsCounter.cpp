#include "FpsCounter.h"

FpsCounter::FpsCounter(std::string UID)
	: GameObject(UID)
{
}

void FpsCounter::Start()
{
    transform->SetLocalPosition(400.0f, 300.0f);
    textRenderer = AddComponent<TextRenderer>();

    textRenderer->SetFont(AssetLoader::GetFont("roboto.ttf"));
    (*textRenderer)("INIT");
}

void FpsCounter::Update()
{
    (*textRenderer)("FPS: " + std::to_string((int)Time::FPS()));
}
