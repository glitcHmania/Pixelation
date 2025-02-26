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
            auto obj = game.objectManager.Instantiate<GameObject>();
            auto transform = obj->GetComponent<Transform>();
            transform->Scale({1.0f,1.0f});
            transform->SetLocalPosition(300.0f * i, 300.0f * i);
            transform->Rotate(0.0f);
        
            auto sr = obj->AddComponent<SpriteRenderer>();

            sr->SetTexture(AssetLoader::GetTexture("chest.png"));
            //ObjectManager::Destroy(obj);
        }

		game.objectManager.DestroyAll();

        for (int i = 0; i < 1000; i++)
        {
            auto obj = game.objectManager.Instantiate<GameObject>();
            auto transform = obj->GetComponent<Transform>();
            transform->Scale({ 1.0f,1.0f });
            transform->SetLocalPosition(300.0f * i, 300.0f * i);
            transform->Rotate(0.0f);

            auto sr = obj->AddComponent<SpriteRenderer>();

            sr->SetTexture(AssetLoader::GetTexture("chest.png"));
            //ObjectManager::Destroy(obj);
        }

        game.objectManager.DestroyAll();

        for (int i = 0; i < 1000; i++)
        {
            auto obj = game.objectManager.Instantiate<GameObject>();
            auto transform = obj->GetComponent<Transform>();
            transform->Scale({ 1.0f,1.0f });
            transform->SetLocalPosition(300.0f * i, 300.0f * i);
            transform->Rotate(0.0f);

            auto sr = obj->AddComponent<SpriteRenderer>();

            sr->SetTexture(AssetLoader::GetTexture("chest.png"));
            //ObjectManager::Destroy(obj);
        }

        game.objectManager.DestroyAll();

        for (int i = 0; i < 1000; i++)
        {
            auto obj = game.objectManager.Instantiate<GameObject>();
            auto transform = obj->GetComponent<Transform>();
            transform->Scale({ 1.0f,1.0f });
            transform->SetLocalPosition(300.0f * i, 300.0f * i);
            transform->Rotate(0.0f);

            auto sr = obj->AddComponent<SpriteRenderer>();

            sr->SetTexture(AssetLoader::GetTexture("chest.png"));
            //ObjectManager::Destroy(obj);
        }

		//ObjectManager::Destroy(o);
        //o->Configure(Transform(sf::Vector2f(0.0f,0.0f), 0.0f, sf::Vector2f(1.0f, 1.0f)),"Text");

        //Destroy(o);
        auto o = game.objectManager.Instantiate<FpsCounter>();
        o.use_count();

        game.Loop();
        return 0;
    }
    catch (const std::exception&) 
    {

    }
}

