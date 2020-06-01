#include "OctaveSettingsEntry.h"

#include <QDebug>

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
    // TODO algorithm
}

QString OctaveSettingsEntry::getAlgorithm() const
{
    return "dupa";
}

bool OctaveSettingsEntry::isColorValid() const
{
    return mColor.isValid();
}

bool OctaveSettingsEntry::isAlgorithmValid() const
{
    return mIsAlgorithmValid;
}
