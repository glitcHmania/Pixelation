#pragma once
#include <unordered_map>
#include <queue>
#include <vector>
#include <functional>
#include <typeindex>
#include <any>
#include <SFML/Graphics.hpp>
#include "Events.h"

class EventDispatcher
{
public:
    std::unordered_map<std::type_index, std::vector<std::function<void(const std::any&)>>> listeners;
    std::queue<std::pair<std::type_index, std::any>> eventQueue;

    EventDispatcher() = default;
    ~EventDispatcher() = default;

public:
    static EventDispatcher& GetInstance()
    {
        static EventDispatcher instance;
        return instance;
    }

    EventDispatcher(const EventDispatcher&) = delete;
    void operator=(const EventDispatcher&) = delete;

    template<typename EventType, typename T>
    void Subscribe(std::shared_ptr<T> instance, void (T::* method)(const EventType&)) {
        static_assert(std::is_base_of<GameObject, T>::value, "T must be derived from GameObject");

        std::type_index typeIndex(typeid(EventType));

        auto wrapperFunction = [weakInstance = std::weak_ptr<T>(instance), method](const std::any& event) {
            if (auto sharedInstance = weakInstance.lock()) {  // Ensure object is still alive
                (sharedInstance.get()->*method)(std::any_cast<const EventType&>(event));
            }
            };

        listeners[typeIndex].push_back(wrapperFunction);
    }

    template<typename EventType>
    void Register(std::function<void(const EventType&)> callback) {
        std::type_index typeIndex(typeid(EventType));

        auto wrapperFunction = [callback](const std::any& event) {
            callback(std::any_cast<const EventType&>(event));
            };

        listeners[typeIndex].push_back(wrapperFunction);
    }

    // Dispatch an event immediately
    template<typename EventType>
    void DispatchImmediate(const EventType& event)
    {
        std::type_index typeIndex(typeid(EventType));

        auto it = listeners.find(typeIndex);
        if (it != listeners.end())
        {
            for (auto& listener : it->second)
            {
                listener(event);
            }
        }
    }

    // Dispatch queued events
    template<typename EventType>
    void DispatchQueued(const EventType& event)
    {
        eventQueue.emplace(std::type_index(typeid(EventType)), event);
    }

    // Process queued events
    void ProcessQueuedEvents()
    {
        while (!eventQueue.empty())
        {
            auto [typeIndex, event] = std::move(eventQueue.front());
            eventQueue.pop();

            auto it = listeners.find(typeIndex);
            if (it != listeners.end())
            {
                for (auto& listener : it->second)
                {
                    listener(event);
                }
            }
        }
    }

    // SFML Event Handling
    void HandleSFML()
    {
    }
};