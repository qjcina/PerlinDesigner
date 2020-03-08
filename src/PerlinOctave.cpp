#include "PerlinOctave.h"
#include "NoiseIterator.h"

PerlinOctave::PerlinOctave() = default;

NoiseIterator PerlinOctave::begin() const
{
    return NoiseIterator(mValues, mColor);
}
