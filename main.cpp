#include <SFML/Graphics.hpp>
#include <string>
#include <assert.h>
#include "Window.h"

sf::Sprite& GetSprite(std::string spriteName)
{
    sf::Image image;
    static sf::Texture texture;
    sf::Sprite sprite;

    if (!image.loadFromFile("Assets/" + spriteName)) 
    {
        assert("Couldn't locate the image.");
    }
    if (!texture.loadFromImage(image))
    {
        assert("Couldn't load image to texture.");
    }

    sprite.setTexture(texture);

    return sprite;
}

int main()
{
    Window window({800u,600u},"SEX");

    sf::CircleShape shape1(50);
    shape1.setFillColor(sf::Color::Yellow);
    shape1.setPosition(400, 300);

    sf::Sprite spr;
    spr = GetSprite("PussyDickMonster.png");

    window.Add(spr);

    window.Show();

    return 0;
}
