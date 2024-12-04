#pragma once
#include "Object.h"

class GameObject;
class Transform;

class Component: public Object
{
public:
	Component() = default;

	GameObject* owner = nullptr;
	Transform* transform = nullptr;
};

