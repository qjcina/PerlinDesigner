#include "NoiseCoordinate.h"

#include "CommonFunctions.h"
#include "CommonTypes.h"

NoiseCoordinate::NoiseCoordinate()
{
}

NoiseCoordinate::NoiseCoordinateIndex NoiseCoordinate::getIndex() const
{
    return this->first * PerlinNoise::PerlinArraySize + this->second;
}

bool NoiseCoordinate::hasNext() const
{
    return this->first < PerlinNoise::PerlinArraySize && this->second < PerlinNoise::PerlinArraySize;
}

void NoiseCoordinate::next()
{
    std::pair<uint32_t, uint32_t> newCoordinate = *this;

    if (newCoordinate.second < PerlinNoise::PerlinArraySize - 1) {
        newCoordinate.second++;
    } else {
        newCoordinate.first++;
        newCoordinate.second = 0;
    }
    *this = NoiseCoordinate(newCoordinate);
}

NoiseCoordinate::NoiseCoordinate(const std::pair<uint32_t, uint32_t>& coordinates)
    : std::pair<uint32_t, uint32_t>(coordinates)
{
}

float NoiseCoordinate::getValue(uint32_t valueIndex) const
{
    switch (valueIndex) {
    case 0:
        return normalize(static_cast<float>(this->first) / PerlinNoise::PerlinArraySize);
    case 1:
        return normalize(static_cast<float>(this->second) / PerlinNoise::PerlinArraySize);
    default:
        return 0;
    }
}
