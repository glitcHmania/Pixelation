#include "GameObject.h"
#include <iostream>

GameObject::GameObject()
{
	AddComponent<Transform_C>();
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