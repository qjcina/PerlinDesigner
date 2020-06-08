#pragma once

#include <QColor>
#include <array>

#include "CommonTypes.h"
#include "NoiseGen/INoiseOctave.h"

class Octave2D : public INoiseOctave {
public:
    Octave2D();

    NoiseIterator begin() const override;

    void setColor(const QColor& color) override;
    void setValue(const NoiseCoordinate& position, const float value) override;

private:
    QColor mColor;
    PerlinNoise::ValuesArray mValues;
};
