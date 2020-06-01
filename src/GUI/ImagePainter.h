#pragma once

#include "IImagePainter.h"

#include <QImage>
#include <QQuickPaintedItem>

class IImageData;

class ImagePainter : public IImagePainter {
public:
    ImagePainter();
    void paint(QPainter* painter) override;

    void setImage(const IImageData& imageData);

private:
    QImage mImage;
};