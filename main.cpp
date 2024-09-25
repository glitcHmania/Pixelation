#include <string>
#include "Window.h"
#include "C_Transform.h"

int main()
{
    try {
        Window window({ 800u,600u }, "SEX");
        AssetLoader loader("Assets/");

    Transform tr;
    tr.SetLocalScale({ 5.0f,5.0f });
    tr.SetLocalRotation(10.f);
    tr.SetLocalPosition({ 10.f,10.f });

    tr.Scale({ 2.0f,2.0f });
    tr.Rotate(15.0f);
    tr.Translate({ 7.0f,12.0f });

    sf::CircleShape shape1(50);
    shape1.setFillColor(sf::Color::Yellow);
    shape1.setPosition(400, 300);

        sf::Sprite spr;
        sf::Texture texture;
        loader.FillTextureFromImage("PussyDickMonster.png", texture);
        spr.setTexture(texture);

        window.Add(spr);
        window.Add(shape1);

        window.Show();
        return 0;
    }
    catch (const std::exception&) 
    {

    }
}
