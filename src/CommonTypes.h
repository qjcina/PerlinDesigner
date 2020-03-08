#pragma once

#include <array>
#include <cstdint>

class QColor;

namespace PerlinNoise {

static constexpr size_t const PerlinArraySize = 256;
using PerlinArray = std::array<QColor, PerlinArraySize * PerlinArraySize>;
using ValuesArray = std::array<float, PerlinNoise::PerlinArraySize * PerlinNoise::PerlinArraySize>;

}
