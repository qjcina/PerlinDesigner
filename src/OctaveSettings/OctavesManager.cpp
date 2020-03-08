#include "OctavesManager.h"
#include "OctaveSettingsEntry.h"

#include "PerlinData.h"

OctavesManager& OctavesManager::getInstance()
{
    static OctavesManager instance;
    return instance;
}

void OctavesManager::add(const OctaveSettingsEntry& octave)
{
    mOctavesSettings.push_back(octave);
    refreshImage();
}

void OctavesManager::remove(const OctaveSettingsEntry& octave)
{
    mOctavesSettings.erase(std::remove_if(mOctavesSettings.begin(), mOctavesSettings.end(),
        [&](const std::reference_wrapper<const OctaveSettingsEntry> setting) -> bool {
            return &setting.get() == &octave;
        }));
    refreshImage();
}

void OctavesManager::setPainter(QMLPointer<IImagePainter> painter)
{
    mPainter = painter;
}

void OctavesManager::refreshImage()
{
    qDebug() << "Refreshing";
    PerlinData data;
    if (mPainter.isValid())
        mPainter->setImage(data);
}

OctavesManager::OctavesManager()
    = default;
