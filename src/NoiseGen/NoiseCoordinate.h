#pragma once

#include <vector>

#include "INoiseCoordinate.h"

class NoiseCoordinate : public INoiseCoordinate, private std::pair<uint32_t, uint32_t> {
public:
    NoiseCoordinate();

    NoiseCoordinateIndex getIndex() const override;
    bool hasNext() const override;
    void next() override;
    float getValue(uint32_t valueIndex) const override;

private:
    NoiseCoordinate(const std::pair<uint32_t, uint32_t>& coordinates);
};
