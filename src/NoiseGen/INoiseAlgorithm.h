#pragma once

class QString;
class INoiseCoordinate;

class INoiseAlgorithm {
public:
    virtual operator QString() const = 0;
    virtual float getValue(const INoiseCoordinate& noiseCoordinate) const = 0;
};
