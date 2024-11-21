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
        {
            Camera cam;
            window.SetCamera(cam);
        }


        AssetLoader::ChangePath("Assets/");

        for (int i = 0; i < 100; i++)
        {
            auto obj = Instantiate();
			obj->GetComponent<Transform>()->SetLocalPosition( 75.0f * i, 75.0f * i );
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
