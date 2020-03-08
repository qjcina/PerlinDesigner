#include "PerlinOctave.h"
#include "NoiseIterator.h"

PerlinOctave::PerlinOctave() = default;

NoiseIterator PerlinOctave::begin() const
{
    return NoiseIterator(mValues, mColor);
}

void PerlinOctave::setColor(const QColor& color)
{
    mColor = color;
}

void PerlinOctave::setValue(const Coordinates position, const float value)
{
    mValues[getIndex(position)] = value;
}

size_t PerlinOctave::getIndex(const INoiseOctave::Coordinates& position) const
{
    return position.first * PerlinNoise::PerlinArraySize + position.second;
}
