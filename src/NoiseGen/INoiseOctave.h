#pragma once

#include <cstdint>
#include <utility>

class NoiseIterator;
class QColor;
class NoiseCoordinate;

class INoiseOctave {
public:
    virtual NoiseIterator begin() const = 0;
    virtual NoiseIterator end() const = 0;

    virtual void setColor(const QColor& color) = 0;
    virtual void setValue(const NoiseCoordinate& position, const float value) = 0;

    virtual void normalize() = 0;
};
