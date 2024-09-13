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
    Window window({800u,800u},"GG");

    sf::CircleShape shape1(50);
    shape1.setFillColor(sf::Color::Yellow);
    shape1.setPosition(400, 300);

        spr = GetSprite("chest.png");
        sf::Sprite spr;

    window.Add(shape1);
    window.Add(shape);
    window.Add(shape2);

    window.Discard(2);

    window.Show();

    return 0;
}
