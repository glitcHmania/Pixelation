#include "ObjectManager.h"

namespace ObjectManager
{
	namespace 
	{
		std::unordered_map<std::string, std::shared_ptr<GameObject>> objects;
	}

	std::shared_ptr<GameObject> Instantiate()
	{
		std::shared_ptr<GameObject> ref = std::make_shared<GameObject>(UID::CreateUniqueID());
		objects[ref->GetUID()] = ref;
		return ref;
	}
	void Destroy(std::shared_ptr<GameObject> object)
	{
		std::string id = object->GetUID();
		objects[id]->RemoveAllComponents();
		objects[id].reset();
		objects.erase(id);
	}
}




