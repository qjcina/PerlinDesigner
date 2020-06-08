#pragma once

#include "CommonTypes.h"

#include <QColor>

class NoiseIterator {
public:
    using IteratorIndex = uint32_t;

    NoiseIterator(const PerlinNoise::ValuesArray& values, const QColor& color);
    NoiseIterator(const PerlinNoise::ValuesArray& values, const QColor& color, const IteratorIndex index);

    NoiseIterator& operator++();
    QColor operator*() const;

private:
    const PerlinNoise::ValuesArray& mValues;
    const QColor mColor;
    IteratorIndex mIndex;
};
