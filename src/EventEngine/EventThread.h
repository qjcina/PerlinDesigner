#pragma once

#include <condition_variable>
#include <functional>
#include <memory>
#include <thread>

class EventThread {
public:
    using NotifyFunc = std::function<void(void)>;

    EventThread(NotifyFunc notifyFunction);
    void wakeUp();

private:
    void threadLoop();

    std::thread mThread;
    const NotifyFunc mNotifyFunction;
    std::condition_variable mWaitCondition;
    std::mutex mThreadLock;
};
