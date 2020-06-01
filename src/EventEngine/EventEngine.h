#pragma once

#include "Event.h"
#include "EventListener.h"

#include <mutex>
#include <queue>

class EventThread;

class EventEngine {
public:
    static void RegisterEvent(EventPtr event);
    static void AddEventListener(EventListenerPtr listener);
    static void RemoveListener(EventListenerPtr listener);

private:
    EventEngine();

    static EventEngine& instance();

    void registerEvent(EventPtr event);
    void addEventListener(EventListenerPtr listener);
    void removeListener(EventListenerPtr listener);

    void popEvent();

    std::priority_queue<EventPtr> mEventQueue;
    std::list<EventListenerPtr> mListeners;
    std::unique_ptr<EventThread> mEventThread;
    std::mutex mQueueLock;
    std::mutex mListenersLock;
};
