#pragma once
#include <unordered_map>
#include <memory>
#include <typeindex>
#include <iostream>
#include "Renderer.h"
#include "Transform.h"
#include "Object.h"
#include "UID.h"


class GameObject: public Object
{
public:
	GameObject() = delete;
	GameObject(std::string UID);

	//virtual void Start() = 0;
	//virtual void Update() = 0;
	virtual void Start() {};
	virtual void Update() {};

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
		pComponent->SetID(UID::CreateLongUniqueID());
		pComponent->owner = this;
		pComponent->transform = GetComponent<Transform>().get();
		components[std::type_index(typeid(T))] = pComponent;
		pComponent->Configure();	

		return pComponent;
	}

	template <typename T>
	void RemoveComponent()
	{
		auto it = components.find(typeid(T));
		if (it != components.end())
		{
			it->second.reset();
			it->second->Destruct();
			components.erase(it);
		}
	}

	void RemoveAllComponents();

	const std::string& GetUID() { return id; }

	//DEBUG FUNCTIONS
#ifdef _DEBUG
	void DebugComponents();
#endif

protected:
	Transform* transform = nullptr;

private:
	std::unordered_map<std::type_index, std::shared_ptr<Component>> components;
};
