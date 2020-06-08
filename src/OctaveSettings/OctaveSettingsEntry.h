#pragma once

#include "IOctaveSetting.h"

#include <QColor>
#include <QObject>
#include <memory>

class OctaveSettingsEntry : public IOctaveSetting {
public:
    OctaveSettingsEntry();
    ~OctaveSettingsEntry();

    QString getColorString() const;
    const QColor& getColor() const override;
    void setColor(const QString& colorString);

    void setAlgorithm(const QString& algorithm);
    const std::shared_ptr<INoiseAlgorithm> getAlgorithm() const override;

    bool isColorValid() const;
    bool isAlgorithmValid() const;

signals:
    void colorChanged();
    void algorithmChanged();

private:
    QColor mColor;
    std::shared_ptr<INoiseAlgorithm> mAlgorithm;
    bool mIsAlgorithmValid = true;
};
