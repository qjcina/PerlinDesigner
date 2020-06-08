#pragma once

#include "INoiseAlgorithm.h"
#include <QString>

class INoiseCoordinate;

class NoiseAlgorithm : public INoiseAlgorithm {
public:
    NoiseAlgorithm(const QString& algorithmString);

    float getValue(const INoiseCoordinate& noiseCoordinate) const override;

    operator QString() const override;

private:
    const QString mAlgorithmString;
};
