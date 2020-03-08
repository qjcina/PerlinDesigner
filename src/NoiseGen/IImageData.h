#pragma once

class QImage;

class IImageData {
public:
    virtual QImage getImage() const = 0;
    virtual operator QImage() const = 0;
};
