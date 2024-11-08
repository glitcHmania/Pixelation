#include "ObjectManager.h"

std::shared_ptr<GameObject> ObjectManager::Instantiate()
{
	std::shared_ptr<GameObject> ref = std::make_shared<GameObject>(UID::CreateUniqueID());
	objects[ref->GetUID()] = ref;
	return ref;
}

void ObjectManager::Destroy(std::shared_ptr<GameObject> object)
{
	std::string id = object->GetUID();
	objects[id]->RemoveAllComponents();
	objects[id].reset();
	objects.erase(id);
}

