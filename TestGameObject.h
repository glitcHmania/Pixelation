#pragma once
#include "GameObject.h"
#include "EventDispatcher.h"
#include "Events.h"

class TestGameObject : public GameObject
{
public:

	int dicks = 0;

	TestGameObject(const std::string& id) : GameObject(id) // Pass ID to GameObject
	{
	}

	void Start() override
	{
		std::cout << "TestGameObject Start" << std::endl;
		Subscribe<TestEvent, TestGameObject>(&TestGameObject::PrintDicks);
	}

	void Update() override
	{
	}

	void PrintDicks(const TestEvent& tesetevent )
	{
		std::cout << tesetevent.message << dicks  << " inches" << std::endl;
		dicks++;
	}
};

