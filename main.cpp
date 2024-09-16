#include <string>
#include "Window.h"

int main()
{
    Window window({800u,600u},"SEX");

    sf::CircleShape shape1(50);
    shape1.setFillColor(sf::Color::Yellow);
    shape1.setPosition(400, 300);

    sf::Sprite spr;
    sf::Texture texture;
    window.loader.FillTextureFromImage("PussyDickMonster.png", texture);
    spr.setTexture(texture);

    window.Add(spr);

    window.Show();

    return 0;
}
