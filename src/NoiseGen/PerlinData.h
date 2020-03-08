#pragma once

#include "CommonTypes.h"
#include "IImageData.h"
#include <QColor>
#include <array>
#include <cstdint>

class INoiseOctave;

class PerlinData : public IImageData {
public:
    PerlinData();

    QImage getImage() const override;
    operator QImage() const override;

    void addOctave(const INoiseOctave& array);

private:
    static uint32_t packColor(const QColor& color);
    static QColor averageColor(const QColor& lhs, const QColor& rhs);

    PerlinNoise::PerlinArray mPerlinArray;
};
