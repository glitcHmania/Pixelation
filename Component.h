#pragma once

class GameObject;
class Transform;

class Component
{
public:
	Component() = default;

	GameObject* owner = nullptr;
	Transform* transform = nullptr;
};

