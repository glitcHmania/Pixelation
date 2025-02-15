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
        SpriteRendererPointer = render->get();
        SpriteRendererPointer->MakeUI();
        SpriteRendererPointer->SetTexture(AssetLoader::GetTexture("chest.png"));
        isSprite = true;
    }

    else if (auto render = std::get_if<std::shared_ptr<TextRenderer>>(&renderer)) {
        TextRendererPointer = render->get();
        TextRendererPointer->MakeUI();
        TextRendererPointer->SetFont(AssetLoader::GetFont("roboto.ttf"));
        TextRendererPointer->SetSize(fontSize);
        (*TextRendererPointer)("INIT");
        isSprite = false;
    }
}

void UIObject::Update()
{
    if (isSprite) {
        //
    }
    else {
        (*TextRendererPointer)("" + std::to_string((int)Time::FPS()));
    }
    //(*renderer)("" + std::to_string((int)Time::FPS()));
}

