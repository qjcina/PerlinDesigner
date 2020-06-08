#include "ImagePainter.h"

#include <QPainter>

#include "ImagePainterManager.h"
#include "NoiseGen/IImageData.h"

ImagePainter::ImagePainter()
{
    ImagePainterManager::instance()->registerPainter(QMLPointer(this));
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
        qDebug() << mImage;
    }
}

void ImagePainter::setImage(QImage&& imageData)
{
    mImage = std::move(imageData);
    update();
}
