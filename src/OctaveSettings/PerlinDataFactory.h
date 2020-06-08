#pragma once

#include "IDataFactory.h"
#include "NoiseGen/IImageData.h"
#include "OctaveSettings/OctaveSettingsEntry.h"

#include <memory>

class PerlinDataFactory : public IDataFactory {
public:
    PerlinDataFactory();

    std::unique_ptr<IImageData> getData(const std::vector<OctaveSettingsEntry>& octavesSettings) const override;
};
