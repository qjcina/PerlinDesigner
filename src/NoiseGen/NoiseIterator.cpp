#include "NoiseIterator.h"

NoiseIterator::NoiseIterator(const PerlinNoise::ValuesArray& values, const QColor& color)
    : NoiseIterator(values, color, 0)
{
}

NoiseIterator::NoiseIterator(const PerlinNoise::ValuesArray& values, const QColor& color, const NoiseIterator::IteratorIndex index)
    : mValues(values)
    , mColor(color)
    , mIndex(index)
{
}

NoiseIterator& NoiseIterator::operator++()
{
    mIndex++;
    return *this;
}

QColor NoiseIterator::operator*() const
{
    float value = mValues[mIndex];
    return QColor(value * mColor.red(), value * mColor.green(), value * mColor.blue(), mColor.alpha() * value);
}

bool NoiseIterator::operator==(const NoiseIterator& other) const
{
    return other.mValues.data() == mValues.data() && other.mIndex == mIndex;
}

bool NoiseIterator::operator!=(const NoiseIterator& other) const
{
    return !operator==(other);
}
