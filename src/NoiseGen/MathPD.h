#pragma once

#include <QObject>

class MathPD : public QObject {
    Q_OBJECT
public:
    MathPD();

    Q_INVOKABLE float perlinNoise(qreal xValue, qreal yValue) const;
};
