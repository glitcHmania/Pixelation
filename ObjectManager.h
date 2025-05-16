#pragma once
#include "FiniteMap.h"
#include "GameObject.h"
#include "UID.h"
#include "EventDispatcher.h"

class ObjectManager
{
public:
    // Get the singleton instance
    static ObjectManager& GetInstance();

    // Delete copy and move constructors to enforce singleton behavior
    ObjectManager(const ObjectManager&) = delete;
    ObjectManager& operator=(const ObjectManager&) = delete;

    template <typename T>
    std::shared_ptr<T> Instantiate()
    {
        static_assert(std::is_base_of<GameObject, T>::value, "Tried to push a Non-GameObject inherited class");

        std::string id = UID::CreateUniqueID();
        std::shared_ptr<T> ref = std::make_shared<T>(id);
        ref->order = objects.AddSmart(ref);
        EventDispatcher::GetInstance().RegisterToEvent<DestroyEvent>(&ObjectManager::GetInstance(), &ObjectManager::DestroyByEvent);

        return ref;
    }


    void Destroy(std::shared_ptr<GameObject> object);
    void Destroy(int id);
    void DestroyByEvent(const DestroyEvent& event);
    void DestroyAll();

    void Update();
    void Start();

private:
    ObjectManager(int size = 100000); // Default size, can be changed if needed

    FiniteMap<std::shared_ptr<GameObject>> objects;
    std::vector<std::shared_ptr<GameObject>> destroyQueue;
};
