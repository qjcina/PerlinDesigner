#pragma once

#include "CommonTypes.h"
#include "NoiseGen/IImageData.h"
#include <QColor>
#include <array>
#include <cstdint>

class INoiseOctave;

class AverageValueNoiseData : public IImageData {
public:
    AverageValueNoiseData();

    QImage getImage() const override;
    operator QImage() const override;

    void addOctave(const INoiseOctave& array);

private:
    static uint32_t packColor(const QColor& color);
    static QColor averageColor(const QColor& lhs, const QColor& rhs);

    PerlinNoise::PerlinArray mPerlinArray;
    bool mBaseConstructed = false;
};
