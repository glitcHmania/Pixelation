#include <SFML/Graphics.hpp>
#include <string>
#include <assert.h>

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
    sf::RenderWindow window(sf::VideoMode(800, 600), "My Game!");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        sf::Sprite spr;
        spr = GetSprite("chest.png");

        spr.scale({ 0.5f,0.5f });
        spr.setOrigin({ 235.0f,235.0f });
        spr.setPosition({ 400.0f,300.0f });

        window.draw(spr);
        window.display();
    }

    return 0;
}
