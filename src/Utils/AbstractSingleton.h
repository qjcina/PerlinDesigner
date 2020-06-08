#pragma once

#include <QObject>
#include <QQmlEngine>
#include <memory>

class QJSEngine;

template <class ChildClass>
class AbstractSingleton {
    class ChildClassInstance : public ChildClass {
    public:
        ChildClassInstance()
            : ChildClass() {};
    };

    template <typename ClassType>
    using IsQObject = std::is_base_of<QObject, ClassType>;

public:
    template <typename ChildClassType = ChildClass>
    static std::enable_if<IsQObject<ChildClassType>::value, QObject*> instance(QQmlEngine*, QJSEngine*)
    {
        if (!mInstance) {
            createInstance();
        }
        return mInstance.get();
    }

    static std::shared_ptr<ChildClass> instance()
    {
        if (!mInstance) {
            createInstance();
        }
        return mInstance;
    }

private:
    template <typename ChildClassType = ChildClass>
    static void createInstance()
    {
        mInstance = std::make_shared<ChildClassInstance>();
        if constexpr (IsQObject<ChildClassType>::value) {
            QQmlEngine::setObjectOwnership(mInstance.get(), QQmlEngine::CppOwnership);
        }
    }

    static inline std::shared_ptr<ChildClassInstance> mInstance;
};
