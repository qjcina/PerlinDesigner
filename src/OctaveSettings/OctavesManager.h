#pragma once

#include "CommonTypes.h"
#include "GUI/IImagePainter.h"
#include "IOctaveSetting.h"
#include "NoiseGen/IImageData.h"
#include "PerlinDataFactory.h"
#include "Utils/QMLPointer.h"

#include <functional>
#include <list>
#include <mutex>

class OctaveSettingsEntry;

class OctavesManager {
    using SettingsList = std::vector<QMLPointer<OctaveSettingsEntry>>;

public:
    static OctavesManager& getInstance();

    void add(QMLPointer<OctaveSettingsEntry>&& octave);
    void remove(const QMLPointer<OctaveSettingsEntry>& octave);

    void setPainter(QMLPointer<IImagePainter> painter);

private:
    OctavesManager();

    void refreshImage();

    SettingsList mOctavesSettings;
    QMLPointer<IImagePainter> mPainter;
    PerlinDataFactory mFactory;
};
