#include "PerlinDataFactory.h"

#include "NoiseGen/PerlinData.h"
#include "NoiseGen/PerlinOctave.h"

PerlinDataFactory::PerlinDataFactory()
{
}

std::unique_ptr<IImageData> PerlinDataFactory::getData(const std::vector<OctaveSettingsEntry>& octavesSettings) const
{
    auto perlinData = std::make_unique<PerlinData>();

    for (const auto& octaveSettings : octavesSettings) {
        PerlinOctave octave;
        octave.setColor(octaveSettings.getColor());

        perlinData->addOctave(octave);
    }
}
