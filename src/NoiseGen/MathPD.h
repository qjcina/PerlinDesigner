#pragma once

#include <QObject>

class MathPD : public QObject {
    Q_OBJECT
public:
    MathPD();

    Q_INVOKABLE float perlinNoise(float xValue, float yValue) const;
    Q_INVOKABLE float whiteNoise(float xValue, float yValue) const;
    Q_INVOKABLE float randomNoise(float xValue, float yValue) const;

private:
    int32_t getSeed(float xValue, float yValue) const;
};
