#pragma once
#include <memory>
#include <unordered_map>
#include <typeindex>
#include <iostream>
#include "Renderer.h"
#include "Transform.h"
#include "Object.h"
#include "UID.h"
#include "EventDispatcher.h"
#include "Events.h"
#include "Component.h"

class GameObject : public Object
{
public:
	GameObject() = delete;
	GameObject(std::string UID);

	virtual void Start() {};
	virtual void Update();  // now calls components + OnUpdate
	void Destroy();
	void SetTag(const std::string& tag) { this->tag = tag; }
	const std::string& GetTag() { return tag; }

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
	std::shared_ptr<T> GetComponentByBase()
	{
		for (auto& [type, component] : components)
		{
			std::shared_ptr<T> casted = std::dynamic_pointer_cast<T>(component);
			if (casted) return casted;
		}
		return nullptr;
	}


	template <typename T>
	std::shared_ptr<T> AddComponent()
	{
		std::shared_ptr<T> pComponent = std::make_shared<T>();
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
			it->second->Destruct();
			it->second.reset();
			components.erase(it);
		}
	}

	void RemoveAllComponents();

	const std::string& GetUID() { return id; }

#ifdef _DEBUG
	void DebugComponents();
#endif

public:
	Transform* transform = nullptr;
	int order;

protected:
	virtual void OnUpdate() {}  // override this in subclasses

private:
	std::unordered_map<std::type_index, std::shared_ptr<Component>> components;
	std::string tag;
};
