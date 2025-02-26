#pragma once
#include <SFML/Graphics.hpp>

struct EventBase
{
	virtual ~EventBase() {}
};

struct DestroyEvent: public EventBase
{
	DestroyEvent(int id) : id(id) {}
	int id;
};

struct TestEvent : public EventBase
{
	TestEvent(const std::string& message) : message(message) {}
	std::string message;
};

struct SFMLEvent : public EventBase
{
	sf::Event event;
};

struct CameraMoved : public EventBase
{
	sf::Vector2f position;
};

struct WindowCloseEvent {};
struct KeyPressedEvent
{
	sf::Keyboard::Key key;
};
struct MouseClickEvent
{
	int x, y;
	sf::Mouse::Button button;
};