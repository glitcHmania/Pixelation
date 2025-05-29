#include "Game.h"
#include "UIObject.h"
#include "AssetLoader.h"
#include "ComponentIncluder.h"
#include "ObjectManager.h"
#include "FpsCounter.h"
#include "FiniteMap.h"

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

        //for (int i = 0; i < 10000; i++)
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

        //TestCollisionListener listener;
        //EventDispatcher::GetInstance().RegisterToEvent<CollisionEvent>(&listener, &TestCollisionListener::OnCollision);

        // Ground object
        auto ground = ObjectManager::GetInstance().Instantiate<GameObject>();
        ground->AddComponent<BoxCollider>();
        ground->AddComponent<SpriteRenderer>()->SetTexture(AssetLoader::GetTexture("abcd.png"));
		//ground->AddComponent<Rigidbody>()->useGravity = false; // Make ground kinematic
        ground->transform->SetLocalPosition(400.0f, -150.0f);
        ground->transform->SetLocalScale({ 100.0f, 100.0f }); // Scale ground 3x wide
		ground->transform->SetLocalRotation(-90.0f);

        // Falling object
        auto falling = ObjectManager::GetInstance().Instantiate<GameObject>();
        falling->AddComponent<BoxCollider>();
        auto x = falling->AddComponent<Rigidbody>();
        falling->AddComponent<SpriteRenderer>()->SetTexture(AssetLoader::GetTexture("chest.png"));
        x->SetMass(30.0f);
        x->transform->SetLocalRotation(45.0f);
        //x->ApplyForce(sf::Vector2f(10000.0f, 0.0f));
        falling->transform->SetLocalPosition(400.0f, -0.0f);
        falling->transform->SetLocalScale({ 1.0f, 2.0f });

        game.Loop();
        return 0;
    }
    catch (const std::exception&) 
    {

    }
}

