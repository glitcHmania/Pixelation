#include <SFML/Graphics.hpp>
#include <string>
#include <assert.h>
#include "Window.h"
#include "C_Transform.h"

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

    window.Discard(2);

    window.Show();

    return 0;
}
