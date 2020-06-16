#pragma once

#include <algorithm>

#include "CommonTypes.h"

namespace CommonFunctions {

template <typename Type>
Type clamp(const Type& value, const Type& minValue, const Type& maxValue)
{
    if (value > maxValue)
        return maxValue;
    if (value < minValue)
        return minValue;
    return value;
}

template <typename Type, typename OtherType>
Type clamp(const Type& value, const OtherType& minValue, const OtherType& maxValue)
{
    return clamp(value, static_cast<Type>(minValue), static_cast<Type>(maxValue));
}

template <typename Type>
Type normalize(const Type& value, const Type& maxValue)
{
    return clamp(value / maxValue, static_cast<Type>(0), static_cast<Type>(1));
}

template <class Container>
Container normalize(const Container& container)
{
    Container newContainer;

    if constexpr (!std::is_same<PerlinNoise::ValuesArray, Container>::value)
        newContainer.resize(container.size());
    const auto maxElement = *std::max_element(container.begin(), container.end());

    std::transform(container.begin(), container.end(), newContainer.begin(), [&](const decltype(maxElement) element) {
        return normalize(element, maxElement);
    });

    return newContainer;
}

}
