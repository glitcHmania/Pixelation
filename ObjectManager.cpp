#include "ObjectManager.h"

ObjectManager::ObjectManager(int size)
{
	objects.ResetToSize(size);
}

void ObjectManager::Destroy(std::shared_ptr<GameObject> object)
{
	int i = object->order;
	if (!objects.isNull(i))
	{
		objects[i]->RemoveAllComponents();
		objects.DeleteSmart(objects[i]->order);
	}
}

void ObjectManager::Destroy(int id)
{
	if(!objects.isNull(id))
	{
		objects[id]->RemoveAllComponents();
		objects.DeleteSmart(id);
		std::cout << "Object " << id << " destroyed.";
	}
}

void ObjectManager::DestroyAll()
{
	for (int i = 0; i < objects.size; i++)
	{
		if (!objects.isNull(i))
		{
			objects[i]->RemoveAllComponents();
			objects.DeleteSmart(objects[i]->order);
		}
	}
	objects.Clear();
}

void ObjectManager::Update()
{
	for (int i = 0; i < objects.size; i++)
	{
		if (!objects.isNull(i))
		{
			objects[i]->Update();
		}
	}
}

void ObjectManager::Start()
{
	for (int i = 0; i < objects.size; i++)
	{
		if (!objects.isNull(i))
		{
			objects[i]->Start();
		}
	}
}
