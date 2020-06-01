#include "EventEngine.h"
#include "EventThread.h"

void EventEngine::RegisterEvent(EventPtr event)
{
    instance().registerEvent(event);
}

void EventEngine::AddEventListener(EventListenerPtr listener)
{
    instance().addEventListener(listener);
}

void EventEngine::RemoveListener(EventListenerPtr listener)
{
    instance().removeListener(listener);
}

EventEngine::EventEngine()
    : mEventThread(std::make_unique<EventThread>(std::bind(&EventEngine::popEvent, this)))
{
}

EventEngine& EventEngine::instance()
{
    static EventEngine eventEngine;
    return eventEngine;
}

void EventEngine::registerEvent(EventPtr event)
{
    std::lock_guard lock(mQueueLock);
    mEventQueue.push(event);
    if (mEventThread)
        mEventThread->wakeUp();
}

void EventEngine::addEventListener(EventListenerPtr listener)
{
    std::lock_guard lock(mListenersLock);
    mListeners.push_back(listener);
}

void EventEngine::removeListener(EventListenerPtr listener)
{
    std::lock_guard lock(mListenersLock);
    mListeners.remove(listener);
}

void EventEngine::popEvent()
{
    while (!mEventQueue.empty()) {
        EventPtr event;
        {
            std::lock_guard lock(mQueueLock);
            event = mEventQueue.top();
            mEventQueue.pop();
        }

        if (!event)
            continue;

        std::lock_guard lock(mListenersLock);
        for (const auto& listener : mListeners) {
            if (listener->getListenedType() == event->getType())
                listener->notify();
        }
    }
}
