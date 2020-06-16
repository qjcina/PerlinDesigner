#pragma once

template <typename Type>
Type clamp(const Type& value, const Type& minValue, const Type& maxValue)
{
    if (value > maxValue)
        return maxValue;
    if (value < minValue)
        return minValue;
    return value;
}

template <typename Type>
Type normalize(const Type& value)
{
    return clamp(value, static_cast<Type>(0), static_cast<Type>(1));
}
