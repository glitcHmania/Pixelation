#include "main.h"

int Setup()
{
    auto o = ObjectManager::GetInstance().Instantiate<FpsCounter>();

    // Ground object
    auto ground = ObjectManager::GetInstance().Instantiate<GameObject>();
    ground->AddComponent<BoxCollider>();
    ground->AddComponent<SpriteRenderer>()->SetTexture(AssetLoader::GetTexture("abcd.png"));
    //ground->AddComponent<Rigidbody>()->useGravity = false; // Make ground kinematic
    ground->transform->SetLocalPosition(400.0f, -150.0f);
    ground->transform->SetLocalScale({ 100.0f, 100.0f }); // Scale ground 3x wide
    ground->transform->SetLocalRotation(-5.0f);

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
}
