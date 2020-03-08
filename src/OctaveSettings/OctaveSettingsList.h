#pragma once

#include <functional>
#include <list>

class OctaveSettingsEntry;

class OctaveSettingsList {
public:
    static OctaveSettingsList& getInstance();

    void add(const OctaveSettingsEntry& octave);
    void remove(const OctaveSettingsEntry& octave);

private:
    OctaveSettingsList();

    std::list<std::reference_wrapper<const OctaveSettingsEntry>> mOctavesSettings;
};
