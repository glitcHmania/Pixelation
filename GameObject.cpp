#include "GameObject.h"
#include <iostream>

GameObject::GameObject(std::string UID)
{
	AddComponent<Transform>();
	id = UID;
}

void GameObject::Update()
{
	for (auto& component : components)
	{
		auto& componentPtr = component.second;
		auto componentUpdate = static_cast<Component*>(componentPtr.get());
		componentUpdate->Update();
	}
}

void GameObject::RemoveAllComponents()
{
	for (auto& component : components)
	{
		component.second.reset();
	}
	components.clear();
}

#ifdef _DEBUG
void GameObject::DebugComponents()
{
	std::cout << "GameObjectID: " << id << " | ";
	for (const auto& [typeIndex, component] : components)
	{
		std::cout << "Component: " << typeIndex.name() << " | " << std::endl;
	}
}
#endif