#include "OctaveSettingsEntry.h"

#include "OctaveSettingsList.h"

#include <QDebug>

OctaveSettingsEntry::OctaveSettingsEntry()
{
    OctaveSettingsList::getInstance().add(*this);
}

OctaveSettingsEntry::~OctaveSettingsEntry()
{
    OctaveSettingsList::getInstance().remove(*this);
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
