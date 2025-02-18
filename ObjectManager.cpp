#include "ObjectManager.h"

ObjectManager::ObjectManager(int size)
{
	objects.ResetToSize(size);
}

void ObjectManager::Destroy(std::shared_ptr<GameObject> object)
{
	if (!objects.isNull(object->order))
	{
		int id = object->order;
		objects[id]->Destroy();
	}
}

void ObjectManager::Destroy(int id)
{
	if (!objects.isNull(id))
	{
		objects[id]->Destroy();
	}
	
}

void ObjectManager::DestroyAll()
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

void ObjectManager::ProcessDestroyed()
{
	for (int i = 0; i < objects.size; i++)
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
