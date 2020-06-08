#include "NoiseCoordinate.h"

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
