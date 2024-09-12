#include "Window.h"

int main()
{
    Window window({800u,800u},"GG");

    sf::CircleShape shape(30);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(400, 300);

    sf::CircleShape shape1(50);
    shape1.setFillColor(sf::Color::Yellow);
    shape1.setPosition(200, 0);

    window.Add(shape);
    window.Add(shape1);
    window.Discard(0);

    window.Show();

    return 0;
}