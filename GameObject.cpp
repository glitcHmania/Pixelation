#include "GameObject.h"

GameObject::GameObject(std::string UID)
{
	transform = AddComponent<Transform>().get();
	id = UID;
}

void GameObject::Update()
{
	for (auto& [_, component] : components)
	{
		component->Update(Time::GetDeltatime());
	}
	OnUpdate();
}

void GameObject::Destroy()
{
	EventDispatcher::GetInstance().DispatchQueued<DestroyEvent>(DestroyEvent{ order });
}

void GameObject::RemoveAllComponents()
{
	for (auto& component : components)
	{
		component.second->Destruct();
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
