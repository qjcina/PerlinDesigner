#include "PerlinDataFactory.h"

#include "NoiseGen/PerlinData.h"

PerlinDataFactory::PerlinDataFactory()
{
}

std::unique_ptr<IImageData> PerlinDataFactory::getData() const
{
    std::unique_ptr<PerlinData> data;
    return data;
}
