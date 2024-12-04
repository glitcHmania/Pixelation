#pragma once
#include <vector>
#include <memory>
#include "GameObject.h"
#include "UID.h"


namespace ObjectManager
{
	//DO NOT USE THIS DIRECTLY
	inline std::unordered_map<std::string, std::shared_ptr<GameObject>> objects;

	template <typename T>
	std::shared_ptr<GameObject> Instantiate()
	{
		static_assert(std::is_base_of<GameObject, T>::value, "Tried to push a Non-GameObject inherited class");
		std::string id = UID::CreateUniqueID();
		std::shared_ptr<GameObject> ref = std::make_shared<T>(id);
		objects[id] = ref;
		return ref;
	}

	inline void Destroy(std::shared_ptr<GameObject> object)
	{
		std::string id = object->GetUID();
		objects[id]->RemoveAllComponents();
		objects[id].reset();
		objects.erase(id);
	}

	inline void Update()
	{
		for (const auto& object : objects) 
		{
			object.second->Update();
		}
	}

	inline void Start()
	{
		for (const auto& object : objects) 
		{
			object.second->Start();
		}
	}
};
