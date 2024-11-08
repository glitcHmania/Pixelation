#include <string>
#include "Window.h"
#include "Transform.h"
#include "SpriteRenderer.h"
#include "ObjectManager.h"

#define Instantiate() objectManager.Instantiate()
#define Destroy(obj) objectManager.Destroy(obj)

int main()
{
    try 
    {
        Window window({ 800u,600u }, "Window");
        AssetLoader::ChangePath("Assets/");
		ObjectManager objectManager;

        for (int i = 0; i < 100; i++)
        {
            auto obj = Instantiate();
			obj->GetComponent<Transform>()->SetLocalPosition( sf::Vector2f(15.0f * i, 12.0f * i) );
            auto sr = obj->AddComponent<SpriteRenderer>();
            sr->SetTexture(AssetLoader::GetTexture("chest.png"));
            window.Add(sr);
        }

        window.Show();
        return 0;
    }
    catch (const std::exception&) 
    {

    }
}

