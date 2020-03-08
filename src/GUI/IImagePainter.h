#pragma once

#include <QQuickPaintedItem>

class IImageData;

class IImagePainter : public QQuickPaintedItem {
public:
    virtual void setImage(const IImageData& imageData) = 0;
};
