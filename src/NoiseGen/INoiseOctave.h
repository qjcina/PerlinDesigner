#pragma once

#include <cstdint>
#include <utility>

class NoiseIterator;
class QColor;

class INoiseOctave {
public:
    using Coordinates = std::pair<uint32_t, uint32_t>;

    virtual NoiseIterator begin() const = 0;

    virtual void setColor(const QColor& color) = 0;
    virtual void setValue(const Coordinates position, const float value) = 0;
};
