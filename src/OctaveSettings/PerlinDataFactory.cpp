#include "PerlinDataFactory.h"

#include "NoiseGen/AverageValueNoiseData.h"
#include "NoiseGen/INoiseAlgorithm.h"
#include "NoiseGen/Octave2D.h"

#include "NoiseGen/NoiseCoordinate.h"

PerlinDataFactory::PerlinDataFactory()
{
}

std::unique_ptr<IImageData> PerlinDataFactory::getData(const std::vector<OctaveSettingsEntry>& octavesSettings) const
{
    auto noiseData = std::make_unique<AverageValueNoiseData>();

    for (const auto& octaveSettings : octavesSettings) {
        Octave2D octave;
        octave.setColor(octaveSettings.getColor());
        NoiseCoordinate coordinate;
        const auto octaveAlgorithm = octaveSettings.getAlgorithm();

        if (!octaveAlgorithm)
            continue;

        do {
            octave.setValue(coordinate, octaveAlgorithm->getValue(coordinate));
            coordinate.next();
        } while (coordinate.hasNext());

        octave.normalize();
        noiseData->addOctave(octave);
    }

    return noiseData;
}
