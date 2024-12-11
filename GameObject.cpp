#include "GameObject.h"

GameObject::GameObject(std::string UID)
{
	transform = AddComponent<Transform>().get();
	id = UID;
}

void GameObject::RemoveAllComponents()
{
	for (auto& component : components)
	{
		auto it = component.second;
		it->Destruct();
		it.reset();
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