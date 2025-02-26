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
		EventDispatcher::GetInstance().Subscribe<TestEvent>([this](const TestEvent& event) { this->PrintDicks(event); });
	}

	void Update() override
	{
		//EventDispatcher::GetInstance().DispatchImmediate<TestEvent>(TestEvent{ "Hello from TestGameObject" });
	}

	void PrintDicks(const TestEvent& tesetevent )
	{
		std::cout << tesetevent.message << dicks  << " inches" << std::endl;
		dicks++;
	}
};

