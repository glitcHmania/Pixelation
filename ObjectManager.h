#pragma once
#include "FiniteMap.h"
#include "GameObject.h"
#include "UID.h"


class ObjectManager
{
public:

	ObjectManager(int size);

	template <typename T>
	std::shared_ptr<T> Instantiate()
	{
		static_assert(std::is_base_of<GameObject, T>::value, "Tried to push a Non-GameObject inherited class");
		std::string id = UID::CreateUniqueID();
		std::shared_ptr<T> ref = std::make_shared<T>(id);
		ref->order = objects.AddSmart(ref);
		return ref;
	}

	void Destroy(std::shared_ptr<GameObject> object);
	void Destroy(int id);
	void DestroyAll();
	void ProcessDestroyed();

	void Update();
	void Start();
private:
	FiniteMap<std::shared_ptr<GameObject>> objects;
};
