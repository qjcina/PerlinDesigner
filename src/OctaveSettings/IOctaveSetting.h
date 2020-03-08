#pragma once

class QColor;

class IOctaveSetting {
public:
    virtual const QColor& getColor() const = 0;
};
