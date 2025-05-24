#pragma once
#include "Object.h"

class GameObject;
class Transform;

class Component : public Object
{
public:
	Component() = default;

	virtual void Configure() {};
	virtual void Destruct() {};
	virtual void Update(float deltaTime) {};  //gets called every frame

	void SetID(std::string UID) { id = UID; }
	std::string GetID() const { return id; }

	GameObject* owner = nullptr;
	Transform* transform = nullptr;
};
