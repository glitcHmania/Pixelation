#include "Game.h"
#include "UIObject.h"
#include "AssetLoader.h"
#include "ComponentIncluder.h"
#include "ObjectManager.h"
#include "FpsCounter.h"
#include "FiniteMap.h"
#include "Player.h"

class TestCollisionListener
{
public:
    void OnCollision(const CollisionEvent& evt)
    {
        std::cout << "Collision detected between "
            << evt.colliderA->GetUID() << " and " << evt.colliderB->GetUID()
            << " | isTrigger = " << std::boolalpha << evt.isTrigger << "\n";
    }
};


int main()
{
    try 
    {
        Game game({ 800u,600u });
        Renderer::CreateCamera();
        AssetLoader::LoadFromDir("Assets/");
        //{
        //    auto ob = ObjectManager::GetInstance().Instantiate<TestGameObject>();
        //    ob->Destroy();
        //    ObjectManager::GetInstance().Destroy(ob);
        //}
        auto o = ObjectManager::GetInstance().Instantiate<FpsCounter>();

        //for (int i = 0; i < 1000; i++)
        //{
        //    auto obj = ObjectManager::GetInstance().Instantiate<GameObject>();
        //    auto transform = obj->GetComponent<Transform>();
        //    transform->SetLocalPosition(150.0f * i,  300.0f * i);
        //    transform->Rotate(0.0f);
        //
        //    auto sr = obj->AddComponent<SpriteRenderer>();
        //
        //    sr->SetTexture(AssetLoader::GetTexture("abcd.png"));
        //}
        
		/*auto p1 = ObjectManager::GetInstance().Instantiate<Player>();
        p1->SetSide(0);
        p1->AddComponent<SpriteRenderer>()->SetTexture(AssetLoader::GetTexture("abcd.png"));

		auto p2 = ObjectManager::GetInstance().Instantiate<Player>();
		p2->SetSide(1);
		p2->AddComponent<SpriteRenderer>()->SetTexture(AssetLoader::GetTexture("chest.png"));*/

        TestCollisionListener listener;
        EventDispatcher::GetInstance().RegisterToEvent<CollisionEvent>(&listener, &TestCollisionListener::OnCollision);

        // Ground object
        auto ground = ObjectManager::GetInstance().Instantiate<GameObject>();
        ground->transform->SetLocalPosition(400.0f, -600.0f);
        ground->transform->SetLocalScale({ 300.0f, 100.0f }); // Scale ground 3x wide
        ground->AddComponent<BoxCollider>();
        ground->AddComponent<SpriteRenderer>()->SetTexture(AssetLoader::GetTexture("chest.png"));

        // Falling object
        auto falling = ObjectManager::GetInstance().Instantiate<GameObject>();
        falling->transform->SetLocalPosition(400.0f, -400.0f);
        falling->transform->SetLocalScale({ 100.0f, 100.0f }); // Normal scale
        falling->AddComponent<BoxCollider>();
        falling->AddComponent<Rigidbody>();
        falling->AddComponent<SpriteRenderer>()->SetTexture(AssetLoader::GetTexture("chest.png"));

        game.Loop();
        return 0;
    }
    catch (const std::exception&) 
    {

    }
}

