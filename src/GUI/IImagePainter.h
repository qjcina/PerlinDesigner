#pragma once

#include <QQuickPaintedItem>

class IImageData;

class IImagePainter : public QQuickPaintedItem {
public:
    virtual void setImage(QImage&& imageData) = 0;
};
