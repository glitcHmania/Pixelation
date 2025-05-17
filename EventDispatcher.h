#pragma once
#include <unordered_map>
#include <queue>
#include <vector>
#include <functional>
#include <typeindex>
#include <any>
#include <SFML/Graphics.hpp>
#include "Events.h"
#include "GameObject.h"

class EventDispatcher
{
public:
    using EventHandler = std::function<void(const std::any&)>;

private:
    std::unordered_map<std::type_index, std::vector<std::pair<void*, EventHandler>>> listeners;
    std::queue<std::pair<std::type_index, std::any>> eventQueue;

public:
    static EventDispatcher& GetInstance()
    {
        static EventDispatcher instance;
        return instance;
    }

    EventDispatcher() = default;
    ~EventDispatcher() = default;

    EventDispatcher(const EventDispatcher&) = delete;
    void operator=(const EventDispatcher&) = delete;

    // Register a member function to an event
    template<typename EventType, typename T>
    void RegisterToEvent(T* instance, void (T::* memberFunc)(const EventType&))
    {
        std::type_index typeIndex(typeid(EventType));

        auto wrapperFunction = [instance, memberFunc](const std::any& event)
            {
                (instance->*memberFunc)(std::any_cast<const EventType&>(event));
            };

        listeners[typeIndex].emplace_back(instance, wrapperFunction);
    }

    // Unregister from an event
    template<typename EventType>
    void UnregisterFromEvent(GameObject* obj)
    {
        std::type_index typeIndex(typeid(EventType));

        auto it = listeners.find(typeIndex);
        if (it != listeners.end())
        {
            it->second.erase(
                std::remove_if(it->second.begin(), it->second.end(),
                    [obj](const auto& pair)
                    {
                        return pair.first == obj;
                    }),
                it->second.end()
            );

            if (it->second.empty())
            {
                listeners.erase(it);
            }
        }
        else 
        {
			throw std::runtime_error("event not found");
        }
    }

    void UnregisterFromAllEvents(GameObject* obj)
    {
        for (auto it = listeners.begin(); it != listeners.end();)
        {
            it->second.erase(
                std::remove_if(it->second.begin(), it->second.end(),
                    [obj](const auto& pair)
                    {
                        return pair.first == obj;
                    }),
                it->second.end()
            );

            if (it->second.empty())
            {
                it = listeners.erase(it);
            }
            else
            {
                ++it;
            }
        }
    }

    // Dispatch an event immediately
    template<typename EventType>
    void DispatchImmediate(const EventType& event)
    {
        std::type_index typeIndex(typeid(EventType));

        auto it = listeners.find(typeIndex);
        if (it != listeners.end())
        {
            for (auto& [obj, listener] : it->second)
            {
                if (obj != nullptr)
                {
                    listener(event);
                }
            }
        }
    }

    // Queue an event for later processing
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
                for (auto& [obj, listener] : it->second)
                {
                    if (obj != nullptr)
                    {
                        listener(event);
                    }
                }
            }
        }
    }
};
