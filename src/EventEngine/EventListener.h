#pragma once

#include "Event.h"

#include <QObject>

class EventListener : public QObject {
    Q_OBJECT
public:
    EventListener(const Event::Type& listenedType);

    void notify();
    const Event::Type& getListenedType() const;

signals:
    void eventHappened();

private:
    const Event::Type mListenedType;
};

using EventListenerPtr = std::shared_ptr<EventListener>;
