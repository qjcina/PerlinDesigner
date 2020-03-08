#pragma once

#include "../GUI/IImagePainter.h"
#include "../IImageData.h"
#include "../Utils/QMLPointer.h"
#include "IOctaveSetting.h"

#include <functional>
#include <list>
#include <mutex>

class OctaveSettingsEntry;

class OctavesManager {
    using List = std::list<std::reference_wrapper<const OctaveSettingsEntry>>;

public:
    static OctavesManager& getInstance();

    void add(const OctaveSettingsEntry& octave);
    void remove(const OctaveSettingsEntry& octave);

    void setPainter(QMLPointer<IImagePainter> painter);

private:
    OctavesManager();

    void refreshImage();

    List mOctavesSettings;
    QMLPointer<IImagePainter> mPainter;
};
