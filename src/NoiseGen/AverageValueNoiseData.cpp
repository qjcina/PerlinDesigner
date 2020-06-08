#include "AverageValueNoiseData.h"

#include <QDebug>
#include <QPixmap>

#include "NoiseGen/INoiseOctave.h"
#include "NoiseGen/NoiseIterator.h"

AverageValueNoiseData::AverageValueNoiseData() = default;

QImage AverageValueNoiseData::getImage() const
{
    std::vector<uint32_t>* colors = new std::vector<uint32_t>();
    std::transform(mPerlinArray.begin(), mPerlinArray.end(), std::back_inserter(*colors),
        packColor);

    return QImage(reinterpret_cast<uint8_t*>(colors->data()),
        PerlinNoise::PerlinArraySize, PerlinNoise::PerlinArraySize,
        QImage::Format_RGB32);
}

void AverageValueNoiseData::addOctave(const INoiseOctave& array)
{
    std::transform(mPerlinArray.begin(), mPerlinArray.end(), array.begin(), mPerlinArray.begin(),
        averageColor);
}

uint32_t AverageValueNoiseData::packColor(const QColor& color)
{
    return color.rgb();
}

QColor AverageValueNoiseData::averageColor(const QColor& lhs, const QColor& rhs)
{
    return QColor((lhs.red() + rhs.red()) / 2,
        (lhs.green() + rhs.green()) / 2,
        (lhs.blue() + rhs.blue()) / 2);
}

AverageValueNoiseData::operator QImage() const
{
    return getImage();
}
