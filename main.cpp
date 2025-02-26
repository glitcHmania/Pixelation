#include "Game.h"
#include "UIObject.h"
#include "AssetLoader.h"
#include "ComponentIncluder.h"
#include "ObjectManager.h"
#include "FpsCounter.h"
#include "FiniteMap.h"
#include "TestGameObject.h"

int main()
{
    try 
    {
        Game game({ 800u,600u });
        Renderer::CreateCamera();
        AssetLoader::LoadFromDir("Assets/");
        {

            auto ob = game.objectManager.Instantiate<TestGameObject>();
            ob->Destroy();
        }

        for (int i = 0; i < 100; i++)
        {
            auto obj = game.objectManager.Instantiate<GameObject>();
            auto transform = obj->GetComponent<Transform>();
            transform->Scale({1.0f,1.0f});
            transform->SetLocalPosition(300.0f * i, 300.0f * i);
            transform->Rotate(0.0f);
        
            auto sr = obj->AddComponent<SpriteRenderer>();

            sr->SetTexture(AssetLoader::GetTexture("chest.png"));
        }
        //clear event dispatcher listeners
        auto o = game.objectManager.Instantiate<FpsCounter>();

        game.Loop();
        return 0;
    }
    catch (const std::exception&) 
    {

    }
}

