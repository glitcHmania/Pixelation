#pragma once
#include "GameObject.h"
#include "EventDispatcher.h"
#include "Events.h"

class TestGameObject : public GameObject
{
public:

	int times = 0;

	TestGameObject(const std::string& id) : GameObject(id) // Pass ID to GameObject
	{
	}

	void Start() override
	{
		std::cout << "TestGameObject Start" << std::endl;
		EventDispatcher::GetInstance().RegisterToEvent<TestEvent>(this, &TestGameObject::PrintTest);
	}

	void Update() override
	{
	}

	void PrintTest(const TestEvent& tesetevent)
	{
		std::cout << tesetevent.message << times << " times" << std::endl;
		times++;
	}
};

