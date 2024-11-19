#include "Window.h"
#include "AssetLoader.h"
#include "ComponentIncluder.h"
#include "ObjectManager.h"

#define Instantiate() ObjectManager::Instantiate()
#define Destroy(obj) ObjectManager::Destroy(obj)

int main()
{
    try 
    {
        Window window({ 800u,600u }, "Window");
        std::shared_ptr<Camera> cam = std::make_shared<Camera>(window.GetRenderWindow());
        window.SetCamera(cam);

        AssetLoader::ChangePath("Assets/");

        for (int i = 0; i < 100; i++)
        {
            auto obj = Instantiate();
			obj->GetComponent<Transform>()->SetLocalPosition( 15.0f * i, 12.0f * i );
            auto sr = obj->AddComponent<SpriteRenderer>();
            sr->SetTexture(AssetLoader::GetTexture("chest.png"));
            window.Add(sr);
        }
        auto o = Instantiate();
        Destroy(o);

        window.Show();
        return 0;
    }
    catch (const std::exception&) 
    {

    }
}
