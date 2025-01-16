#pragma once
#include "Object.h"

class GameObject;
class Transform;

class Component: public Object
{
public:
	Component() = default;
	virtual void Configure() {};

	GameObject* owner = nullptr;
	Transform* transform = nullptr;
};

