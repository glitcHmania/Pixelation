#include "ObjectManager.h"
#include <iostream>

// Singleton instance
ObjectManager& ObjectManager::GetInstance()
{
    static ObjectManager instance;
    return instance;
}

// Private constructor with default size
ObjectManager::ObjectManager(int size)
{
    objects.ResetToSize(size);
}

void ObjectManager::Destroy(std::shared_ptr<GameObject> object)
{
    Destroy(object->order);
}

void ObjectManager::Destroy(int id)
{
    if (!objects.isNull(id))
    {
        EventDispatcher::GetInstance().UnregisterFromAllEvents(objects[id].get());
        objects[id]->RemoveAllComponents();
        objects.DeleteSmart(id);
        std::cout << "Object " << id << " destroyed." << std::endl;
    }
}

void ObjectManager::DestroyByEvent(const DestroyEvent& event)
{
    GetInstance().Destroy(event.id);
}

void ObjectManager::DestroyAll()
{
    for (int i = 0; i < objects.size; i++)
    {
        if (!objects.isNull(i))
        {
            Destroy(objects[i]->order);
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
