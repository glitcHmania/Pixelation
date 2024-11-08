#pragma once
#include <unordered_map>
#include <memory>
#include <typeindex>
#include "Component.h"
#include "Transform.h"

class GameObject
{
public:
	GameObject();
	using UniqueID = std::string;

	void Update();

	template <typename T>
	std::shared_ptr<T> GetComponent()
	{
		auto it = components.find(typeid(T));
		if (it != components.end())
		{
			return std::static_pointer_cast<T>(it->second);
		}
		return nullptr;
	}

	template <typename T>
	std::shared_ptr<T> AddComponent()
	{
		std::shared_ptr<T> pComponent;
		pComponent = std::make_shared<T>();
		pComponent->owner = this;
		pComponent->Construct();
		components[std::type_index(typeid(T))] = pComponent;

		return pComponent;
	}

	template <typename T>
	void RemoveComponent()
	{
		auto it = components.find(typeid(T));
		if (it != components.end())
		{
			it->second.reset();
			components.erase(it);
		}
	}

	void RemoveAllComponents()
	{
		for (auto& component : components)
		{
			component.second.reset();
		}
		components.clear();
	}

	//DEBUG FUNCTIONS
#ifdef _DEBUG
	void DebugComponents();
#endif

public:
	UniqueID id = "";

private:
	std::unordered_map<std::type_index, std::shared_ptr<Component>> components;

};
