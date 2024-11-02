#include <string>
#include "Window.h"
#include "Transform.h"
#include "SpriteRenderer.h"
#include "GameObject.h"


int main()
{
    try 
    {
        Window window({ 800u,600u }, "SEX");
        AssetLoader::ChangePath("Assets/");

		GameObject obj;
        auto sr = obj.AddComponent<SpriteRenderer>();
		sr->SetTexture(AssetLoader::GetTexture("chest.png"));

        sf::CircleShape shape1(50);
        shape1.setFillColor(sf::Color::Yellow);
        shape1.setPosition(400, 300);

        window.Add(sr);
        //window.Add(shape1);

        window.Show();
        return 0;
    }
    catch (const std::exception&) 
    {

    }
}
