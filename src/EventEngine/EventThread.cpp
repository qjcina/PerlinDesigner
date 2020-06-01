#include "EventThread.h"

EventThread::EventThread(NotifyFunc notifyFunction)
    : mThread(&EventThread::threadLoop, this)
    , mNotifyFunction(notifyFunction)
{
}

void EventThread::wakeUp()
{
    std::lock_guard lock(mThreadLock);
    mWaitCondition.notify_one();
}

void EventThread::threadLoop()
{
    std::unique_lock lock(mThreadLock);
    mWaitCondition.wait(lock);
    mNotifyFunction();
}
