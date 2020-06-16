#include "Octave2D.h"
#include "NoiseGen/NoiseIterator.h"

#include "CommonFunctions.h"

#include "NoiseGen/NoiseCoordinate.h"

Octave2D::Octave2D() = default;

NoiseIterator Octave2D::begin() const
{
    return NoiseIterator(mValues, mColor);
}

NoiseIterator Octave2D::end() const
{
    return NoiseIterator(mValues, mColor, mValues.size());
}

void Octave2D::setColor(const QColor& color)
{
    mColor = color;
}

void Octave2D::setValue(const NoiseCoordinate& position, const float value)
{
    mValues[position.getIndex()] = value;
}

void Octave2D::normalize()
{
    mValues = CommonFunctions::normalize(mValues);
}
