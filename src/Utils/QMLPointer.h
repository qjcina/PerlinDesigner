#pragma once

#include <QQuickItem>

template <class T>
class QMLPointer {
    static_assert(std::is_base_of<QQuickItem, T>::value, "QMLPointers have to derive from QQuickItem");

public:
    explicit QMLPointer(T* item)
        : mItem(item)
    {
        if (mItem) {
            QObject::connect(mItem, &QQuickItem::destroyed, [this]() -> void {
                mItem = nullptr;
            });
        }
    }

    QMLPointer() = default;

    T* operator->() const
    {
        return mItem;
    }
    bool isValid() const
    {
        return mItem != nullptr;
    }

private:
    T* mItem = nullptr;
};
