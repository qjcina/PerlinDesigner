#pragma once

class NoiseIterator;

class INoiseOctave {
public:
    virtual NoiseIterator begin() const = 0;
};
