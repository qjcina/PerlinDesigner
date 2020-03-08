#include "OctaveSettingsList.h"
#include "OctaveSettingsEntry.h"

OctaveSettingsList& OctaveSettingsList::getInstance()
{
    static OctaveSettingsList instance;
    return instance;
}

void OctaveSettingsList::add(const OctaveSettingsEntry& octave)
{
    mOctavesSettings.push_back(octave);
}

void OctaveSettingsList::remove(const OctaveSettingsEntry& octave)
{
    mOctavesSettings.erase(std::remove_if(mOctavesSettings.begin(), mOctavesSettings.end(),
        [&](const std::reference_wrapper<const OctaveSettingsEntry> setting) -> bool {
            return &setting.get() == &octave;
        }));
}

OctaveSettingsList::OctaveSettingsList()
    = default;
