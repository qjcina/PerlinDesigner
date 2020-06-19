#include "OctaveSettingsEntry.h"

#include <QDebug>

#include "NoiseGen/INoiseAlgorithm.h"
#include "NoiseGen/NoiseAlgorithm.h"

OctaveSettingsEntry::OctaveSettingsEntry() = default;

OctaveSettingsEntry::~OctaveSettingsEntry() = default;

QString OctaveSettingsEntry::getColorString() const
{
    return mColor.name();
}

const QColor& OctaveSettingsEntry::getColor() const
{
    return mColor;
}

void OctaveSettingsEntry::setColor(const QString& colorString)
{
    mColor = colorString;
}

void OctaveSettingsEntry::setAlgorithm(const QString& algorithm)
{
    // Introduce different noise algorithm calculators
    mAlgorithm = std::make_shared<NoiseAlgorithm>(algorithm);
}

const std::shared_ptr<INoiseAlgorithm> OctaveSettingsEntry::getAlgorithm() const
{
    return mAlgorithm;
}

bool OctaveSettingsEntry::isColorValid() const
{
    return mColor.isValid();
}

bool OctaveSettingsEntry::isAlgorithmValid() const
{
    return mAlgorithm && mAlgorithm->isValid();
}
