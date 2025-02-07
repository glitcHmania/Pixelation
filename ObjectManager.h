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
	std::shared_ptr<T> Instantiate()
	{
		static_assert(std::is_base_of<GameObject, T>::value, "Tried to push a Non-GameObject inherited class");
		std::string id = UID::CreateUniqueID();
		std::shared_ptr<T> ref = std::make_shared<T>(id);
		objects[id] = ref;
		return ref;
	}

	inline void Destroy(std::shared_ptr<GameObject> object)
	{
		std::string id = object->GetUID();
		objects[id]->Destroy();
	}

	inline void Destroy(std::string id)
	{
		objects[id]->Destroy();
	}

	inline void DestroyAll()
	{
		for (int i = 0; i < objects.size(); i++)
		{
			Destroy(objects.begin()->second);
		}
		objects.clear();
	}

	inline void ProcessDestroyed()
	{
		for (auto it = objects.begin(); it != objects.end();)
		{
			if (it->second->IsDestroyed())
			{
				it->second->RemoveAllComponents();
				it = objects.erase(it);
			}
			else
			{
				++it;
			}
		}
	}

	inline std::vector<GameObject*> FindObjectsWithTag(const std::string& tag)
	{
		std::vector<GameObject*> foundObjects;
		for (const auto& object : objects)
		{
			if (object.second->GetTag() == tag)
			{
				foundObjects.push_back(object.second.get());
			}
		}
		return foundObjects;
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
