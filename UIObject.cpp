#include "UIObject.h"

UIObject::UIObject(std::string UID)
	: GameObject(UID)
{
}

void UIObject::Configure(Transform objectConfig, std::string rendererType) {

    if (rendererType == "Sprite") {
        SpriteRendererPointer = AddComponent<SpriteRenderer>();
        isSprite = true;
    }
    else if(rendererType == "Text") {
        TextRendererPointer = AddComponent<TextRenderer>();
        isSprite = false;
    }

    transform->SetLocalPosition(objectConfig.GetLocalPosition());
    transform->SetLocalScale(objectConfig.GetLocalScale());
    transform->SetLocalRotation(objectConfig.GetLocalRotation());
}

void UIObject::Start()
{
    if (isSprite) {
        SpriteRendererPointer->MakeUI();
        SpriteRendererPointer->SetTexture(AssetLoader::GetTexture("chest.png"));
    }

    //For now we only deal with text-sprite renderers, that's why we didn't change this else-if to else.
    else if (!isSprite) {
        TextRendererPointer->MakeUI();
        TextRendererPointer->SetFont(AssetLoader::GetFont("roboto.ttf"));
        TextRendererPointer->SetSize(fontSize);
        (*TextRendererPointer)("INIT");
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

