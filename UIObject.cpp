#include "UIObject.h"

UIObject::UIObject(std::string UID)
	: GameObject(UID)
{
}

void UIObject::Configure(Transform objectConfig, std::string rendererType) {

    if (rendererType == "Sprite") {
        renderer = AddComponent<SpriteRenderer>();
    }
    else if(rendererType == "Text") {
        renderer = AddComponent<TextRenderer>();
    }

    transform->SetLocalPosition(objectConfig.GetLocalPosition());
    transform->SetLocalScale(objectConfig.GetLocalScale());
    transform->SetLocalRotation(objectConfig.GetLocalRotation());
}

void UIObject::Start()
{
    if (auto render = std::get_if<std::shared_ptr<SpriteRenderer>>(&renderer)) {
        SpriteRenderer* rendererPointer = render->get();
        rendererPointer->MakeUI();
        rendererPointer->SetTexture(AssetLoader::GetTexture("chest.png"));
    }

    else if (auto render = std::get_if<std::shared_ptr<TextRenderer>>(&renderer)) {
        TextRenderer* rendererPointer = render->get();
        rendererPointer->MakeUI();
        rendererPointer->SetFont(AssetLoader::GetFont("roboto.ttf"));
        rendererPointer->SetSize(fontSize);
        (*rendererPointer)("INIT");

    }
}

void UIObject::Update()
{
    //(*renderer)("" + std::to_string((int)Time::FPS()));
}

