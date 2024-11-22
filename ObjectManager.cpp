#include "ObjectManager.h"


namespace ObjectManager
{
	void Destroy(std::shared_ptr<GameObject> object)
	{
		std::string id = object->GetUID();
		objects[id]->RemoveAllComponents();
		objects[id].reset();
		objects.erase(id);
	}

	void Update()
	{
		for (auto& object : objects)
		{
			object.second->Update();
		}
	}
}