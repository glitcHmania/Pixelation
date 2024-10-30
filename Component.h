#pragma once

//forward declaration
class GameObject;

class Component
{
public:
	Component() = default;

	virtual void Update() = 0;
	virtual void Construct() = 0;

	GameObject* owner = nullptr;
};

