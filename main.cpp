#include "Window.h"

int main()
{
    Window window({800u,800u},"GG");

    sf::CircleShape shape(30);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(400, 300);

    sf::CircleShape shape1(50);
    shape1.setFillColor(sf::Color::Yellow);
    shape1.setPosition(400, 300);

    sf::CircleShape shape2(20);
    shape2.setFillColor(sf::Color::Magenta);
    shape2.setPosition(500, 200);

    window.Add(shape1);
    window.Add(shape);
    window.Add(shape2);

    window.Discard(2);

    window.Show();

    return 0;
}