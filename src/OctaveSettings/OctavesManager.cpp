#include "OctavesManager.h"
#include "OctaveSettingsEntry.h"

#include "NoiseGen/PerlinData.h"

OctavesManager& OctavesManager::getInstance()
{
    static OctavesManager instance;
    return instance;
}

void OctavesManager::add(QMLPointer<OctaveSettingsEntry>&& octave)
{
    mOctavesSettings.push_back(octave);
    refreshImage();
}

void OctavesManager::remove(const QMLPointer<OctaveSettingsEntry>& octave)
{
    mOctavesSettings.erase(std::remove_if(mOctavesSettings.begin(), mOctavesSettings.end(),
        [&](const QMLPointer<OctaveSettingsEntry>& setting) -> bool {
            return setting == octave;
        }));
    refreshImage();
}

void OctavesManager::setPainter(QMLPointer<IImagePainter> painter)
{
    mPainter = painter;
}

void OctavesManager::refreshImage()
{
    //    if (mPainter.isValid())
    //        mPainter->setImage(data);
}

OctavesManager::OctavesManager()
    = default;
