#include "EventListener.h"

EventListener::EventListener(const Event::Type& listenedType)
    : mListenedType(listenedType)
{
}

void EventListener::notify()
{
    emit eventHappened();
}

const Event::Type& EventListener::getListenedType() const
{
    return mListenedType;
}
