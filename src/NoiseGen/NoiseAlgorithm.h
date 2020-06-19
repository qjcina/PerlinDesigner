#pragma once

#include "INoiseAlgorithm.h"
#include <QJSValue>
#include <QString>

class INoiseCoordinate;

class NoiseAlgorithm : public INoiseAlgorithm {
public:
    NoiseAlgorithm(const QString& algorithmString);

    float getValue(const INoiseCoordinate& noiseCoordinate) const override;
    bool isValid() const override;

    operator QString() const override;

private:
    const QString mAlgorithmString;
    mutable QJSValue mCompiledFunction = QJSValue(QJSValue::NullValue);
};
