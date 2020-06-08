#pragma once

class IImageData;
class OctaveSettingsEntry;

#include <memory>
#include <vector>

class IDataFactory {
public:
    virtual std::unique_ptr<IImageData> getData(const std::vector<OctaveSettingsEntry>& octavesSettings) const = 0;
};
