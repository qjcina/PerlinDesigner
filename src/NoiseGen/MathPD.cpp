#include "MathPD.h"

#include <QDebug>
#include <random>

MathPD::MathPD() = default;

float MathPD::perlinNoise(float xValue, float yValue) const
{
    return 1.0f;
}

float MathPD::whiteNoise(float xValue, float yValue) const
{
    qDebug() << getSeed(xValue, yValue);
    std::mt19937 twister(getSeed(xValue, yValue));
    static std::uniform_int_distribution<int32_t> distibution(0, 1);
    return static_cast<float>(distibution(twister));
}

float MathPD::randomNoise(float xValue, float yValue) const
{
    std::mt19937 twister(getSeed(xValue, yValue));
    static std::uniform_real_distribution<float> distibution(0.0f, 1.0f);
    return static_cast<float>(distibution(twister));
}

int32_t MathPD::getSeed(float xValue, float yValue) const
{
    // TODO: improve me!
    const int32_t xPosition = xValue * std::numeric_limits<int16_t>::max();
    int32_t yPosition = yValue * std::numeric_limits<int16_t>::max();

    yPosition = yPosition != 0 ? yPosition : 1;
    return ((xPosition * yPosition * 60493 + 19990303) + xPosition) - (std::numeric_limits<int16_t>::max() / yPosition);
}
