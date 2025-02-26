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

        auto ob  = ObjectManager::Instantiate<TestGameObject>();

        for (int i = 0; i < 100; i++)
        {
            auto obj = ObjectManager::Instantiate<GameObject>();
            auto transform = obj->GetComponent<Transform>();
            transform->Scale({1.0f,1.0f});
            transform->SetLocalPosition(300.0f * i, 300.0f * i);
            transform->Rotate(0.0f);
        
            auto sr = obj->AddComponent<SpriteRenderer>();

            sr->SetTexture(AssetLoader::GetTexture("chest.png"));
            //ObjectManager::Destroy(obj);
        }
		
		//ObjectManager::Destroy(o);


        //o objesi UIObject'i denemek i�in kullan�ld� burada
        auto o = ObjectManager::Instantiate<FpsCounter>();
        //o->Configure(Transform(sf::Vector2f(0.0f,0.0f), 0.0f, sf::Vector2f(1.0f, 1.0f)),"Text");

        //Destroy(o);

        game.Loop();
        return 0;
    }
    catch (const std::exception&) 
    {

    }
}

