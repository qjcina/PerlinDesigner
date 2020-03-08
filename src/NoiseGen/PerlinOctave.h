#pragma once

#include <QColor>
#include <array>

#include "CommonTypes.h"
#include "INoiseOctave.h"

class PerlinOctave : public INoiseOctave {
public:
    PerlinOctave();

    NoiseIterator begin() const override;

    void setColor(const QColor& color) override;
    void setValue(const Coordinates position, const float value) override;

private:
    size_t getIndex(const Coordinates& position) const;

    QColor mColor;
    PerlinNoise::ValuesArray mValues;
};
