#include "ObjectManager.h"

std::shared_ptr<GameObject> ObjectManager::Instantiate()
{
	std::shared_ptr<GameObject> ref = std::make_shared<GameObject>();
	objects.push_back(ref);
	ref->id = UID::CreateLongUniqueID();
	return ref;
}

void ObjectManager::Destroy(std::shared_ptr<GameObject> object)
{
	for (size_t i =0; i < objects.size(); i++)
	{
		if (objects[i]->id == object->id)
		{
			objects[i]->RemoveAllComponents();
			objects[i].reset();
			objects.erase(objects.begin() + i);
		}
	}
}

