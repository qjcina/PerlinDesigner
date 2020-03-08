#include "ImagePainter.h"

#include <QPainter>

#include "../IImageData.h"
#include "../OctaveSettings/OctavesManager.h"

ImagePainter::ImagePainter()
{
}

void ImagePainter::paint(QPainter* painter)
{
    if (!painter)
        return;

    if (mImage.isNull()) {
        painter->fillRect(boundingRect(), Qt::black);
    } else {
        painter->drawImage(boundingRect(), mImage, mImage.rect(),
            Qt::NoFormatConversion);
    }
}

void ImagePainter::setImage(const IImageData& imageData)
{
    mImage = imageData;
    update();
}
