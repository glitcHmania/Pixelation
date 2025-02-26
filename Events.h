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