#pragma once

#include "IOctaveSetting.h"

#include <QColor>
#include <QObject>

class OctaveSettingsEntry : public IOctaveSetting {
public:
    OctaveSettingsEntry();
    ~OctaveSettingsEntry();

    QString getColorString() const;
    const QColor& getColor() const override;
    void setColor(const QString& colorString);

    void setAlgorithm(const QString& algorithm);
    QString getAlgorithm() const;

    bool isColorValid() const;
    bool isAlgorithmValid() const;

signals:
    void colorChanged();
    void algorithmChanged();

private:
    QColor mColor;
    QString mAlgorithm;
    bool mIsAlgorithmValid = true;
};
