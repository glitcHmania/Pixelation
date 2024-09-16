#include <string>
#include "Window.h"

int main()
{
    try {
        Window window({ 800u,600u }, "SEX");
        AssetLoader loader("Assets/");

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
