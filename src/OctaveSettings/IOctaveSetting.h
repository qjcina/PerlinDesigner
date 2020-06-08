#pragma once

#include <memory>

class QColor;
class INoiseAlgorithm;

class IOctaveSetting {
public:
    virtual const QColor& getColor() const = 0;
    virtual const std::shared_ptr<INoiseAlgorithm> getAlgorithm() const = 0;
};
