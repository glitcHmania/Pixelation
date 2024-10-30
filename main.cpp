#include <string>
#include "Window.h"
#include "Transform_C.h"
#include "SpriteRenderer_C.h"
#include "GameObject.h"


int main()
{
    try 
    {
        Window window({ 800u,600u }, "SEX");
        AssetLoader::ChangePath("Assets/");

		GameObject obj;

		obj.AddComponent<SpriteRenderer_C>()->SetTexture(AssetLoader::GetTexture("chest.png"));

		sf::Sprite sprite;
        sf::Texture tx;
        AssetLoader::FillTextureFromImage(
            "PussyDickMonster.png",
            tx
        );
		sprite.setTexture(tx);


        sf::CircleShape shape1(50);
        shape1.setFillColor(sf::Color::Yellow);
        shape1.setPosition(400, 300);

        window.Add(obj.GetComponent<SpriteRenderer_C>());
        //window.Add(std::make_shared<sf::Sprite> (sprite));

        window.Show();
        return 0;
    }
    catch (const std::exception&) 
    {

    }
}
