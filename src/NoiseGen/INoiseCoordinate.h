#pragma once

#include <cstdint>
#include <memory>

class INoiseCoordinate {
public:
    using NoiseCoordinateIndex = uint32_t;

    virtual NoiseCoordinateIndex getIndex() const = 0;
    virtual bool hasNext() const = 0;
    virtual void next() = 0;
};
