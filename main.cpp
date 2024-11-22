#include "Game.h"
#include "AssetLoader.h"
#include "ComponentIncluder.h"
#include "ObjectManager.h"


#define Destroy(obj) ObjectManager::Destroy(obj)

int main()
{
    try 
    {
        Game game({ 800u,600u });
        game.GetRenderer().CreateCamera();
        AssetLoader::ChangePath("Assets/");


        for (int i = 0; i < 100; i++)
        {
			std::shared_ptr<GameObject> obj = ObjectManager::Instantiate<GameObject>();
            auto transform = obj->GetComponent<Transform>();
            transform->SetLocalPosition(75.0f * i, 75.0f * i);
            transform->Rotate(3.14f);
            transform->Scale({1.5f,1.5f});

            auto sr = obj->AddComponent<SpriteRenderer>();
            sr->SetTexture(AssetLoader::GetTexture("chest.png"));
            game.GetRenderer().AddDrawable(sr);
        }
        auto o = ObjectManager::Instantiate<GameObject>();
        Destroy(o);


        game.Loop();
        return 0;
    }
    catch (const std::exception&) 
    {

    }
}
