#pragma once

#include <QImage>
#include <QQuickPaintedItem>

class IImageData;

class ImagePainter : public QQuickPaintedItem {
public:
    ImagePainter();
    void paint(QPainter* painter) override;

    void setImage(const IImageData& imageData);

private:
    QImage mImage;
};
