#include "OctaveSettingsEntry.h"

#include "OctavesManager.h"

#include <QDebug>

OctaveSettingsEntry::OctaveSettingsEntry()
{
    OctavesManager::getInstance().add(*this);
}

OctaveSettingsEntry::~OctaveSettingsEntry()
{
    OctavesManager::getInstance().remove(*this);
}

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
    if (mColor != colorString) {
        mColor = colorString;
        emit colorChanged();
    }
}

void OctaveSettingsEntry::setAlgorithm(const QString& algorithm)
{
    // TODO algorithm
}

bool OctaveSettingsEntry::isColorValid() const
{
    return mColor.isValid();
}

bool OctaveSettingsEntry::isAlgorithmValid() const
{
    return mIsAlgorithmValid;
}
