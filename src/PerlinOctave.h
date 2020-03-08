#pragma once

#include <QColor>
#include <array>

#include "CommonTypes.h"
#include "INoiseOctave.h"

class PerlinOctave : public INoiseOctave {
public:
    PerlinOctave();

    NoiseIterator begin() const override;

private:
    QColor mColor;
    PerlinNoise::ValuesArray mValues;
};
