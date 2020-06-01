#pragma once

#include <memory>

class Event {
public:
    enum class Type {

    };

    enum class Priority {
        Important,
        Regular
    };

    virtual void execute() const = 0;

    const Type& getType() const
    {
        return mType;
    }

    const Priority& getPriority() const
    {
        return mPriority;
    }

    explicit Event(const Type& eventType, const Priority& priority)
        : mType(eventType)
        , mPriority(priority)
    {
    }

protected:
    const Type mType;
    const Priority mPriority;
};

using EventPtr = std::shared_ptr<Event>;
