#pragma once

#include "NoiseGen/IImageData.h"

#include <memory>

class PerlinDataFactory {
public:
    PerlinDataFactory();

    std::unique_ptr<IImageData> getData() const;
};
