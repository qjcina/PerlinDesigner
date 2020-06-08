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

    template <class OtherT>
    QMLPointer(const QMLPointer<OtherT> other)
    {
        mItem = dynamic_cast<T*>(*other);
    }

    T* operator*() const
    {
        return get();
    }

    T* operator->() const
    {
        return mItem;
    }

    T* get() const
    {
        return mItem;
    }

    bool operator==(const QMLPointer<T>& rhs) const
    {
        return mItem == rhs.mItem;
    }

    bool isValid() const
    {
        return mItem != nullptr;
    }

    operator bool() const
    {
        return isValid();
    }

private:
    T* mItem = nullptr;
};
