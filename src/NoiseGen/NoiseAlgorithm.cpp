#include "NoiseAlgorithm.h"

NoiseAlgorithm::operator QString() const
{
    return mAlgorithmString;
}

NoiseAlgorithm::NoiseAlgorithm(const QString& algorithmString)
    : mAlgorithmString(algorithmString)
{
}

float NoiseAlgorithm::getValue(const INoiseCoordinate& noiseCoordinate) const
{
    return 1;
}
