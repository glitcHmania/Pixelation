#pragma once
#include "FiniteMap.h"
#include "GameObject.h"
#include "UID.h"


namespace ObjectManager
{
	//DO NOT USE THIS DIRECTLY
	inline FiniteMap<std::shared_ptr<GameObject>> objects(10000);

	template <typename T>
	std::shared_ptr<T> Instantiate()
	{
		static_assert(std::is_base_of<GameObject, T>::value, "Tried to push a Non-GameObject inherited class");
		std::string id = UID::CreateUniqueID();
		std::shared_ptr<T> ref = std::make_shared<T>(id);
		ref->order = objects.AddSmart(ref);
		return ref;
	}

	inline void Destroy(std::shared_ptr<GameObject> object)
	{
		if (!objects.isNull(object->order))
		{
			int id = object->order;
			objects[id]->Destroy();
		}
	}

	inline void Destroy(int id)
	{
		if (!objects.isNull(id))
		{
			objects[id]->Destroy();
		}
	}

	inline void DestroyAll()
	{
		for (int i = 0; i < objects.size; i++)
		{
			if (!objects.isNull(i))
			{
				auto x = objects[i];
				Destroy(x);
			}
		}
		objects.Clear();
	}

	inline void ProcessDestroyed()
	{
		for (int i =0; i < objects.size; i++)
		{
			if (!objects.isNull(i))
			{
				if (objects[i]->IsDestroyed())
				{
					auto x = objects[i];
					x->RemoveAllComponents();
					objects.DeleteSmart(i);
				}
			}
		}
	}

	//inline std::vector<GameObject*> FindObjectsWithTag(const std::string& tag)
	//{
	//	std::vector<GameObject*> foundObjects;
	//	for (const auto& object : objects)
	//	{
	//		if (object.second->GetTag() == tag)
	//		{
	//			foundObjects.push_back(object.second.get());
	//		}
	//	}
	//	return foundObjects;
	//}

	inline void Update()
	{
		for (int i = 0; i < objects.size; i++)
		{
			if (!objects.isNull(i))
			{
				objects[i]->Update();
			}
		}
	}

	inline void Start()
	{
		for (int i = 0; i < objects.size; i++)
		{
			if (!objects.isNull(i))
			{
				objects[i]->Start();
			}
		}
	}
};
