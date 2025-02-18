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

void ObjectManager::LateDestroy(std::shared_ptr<GameObject> object)
{
	if (!objects.isNull(object->order))
	{
		int id = object->order;
		objects[id]->Destroy();
		destroyQueue.push_back(objects[id]);
	}
}

void ObjectManager::ProcessLateDestroyed()
{
	if (!destroyQueue.empty())
	{
		for (auto& des : destroyQueue)
		{
			des->RemoveAllComponents();
			objects.DeleteSmart(des->order);
		}
		destroyQueue.clear();
	}
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
