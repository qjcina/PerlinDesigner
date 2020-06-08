#include "ImagePainterManager.h"

ImagePainterManager::ImagePainterManager() = default;

void ImagePainterManager::registerPainter(const QMLPointer<IImagePainter>& painter)
{
    if (mPainter.isValid()) {
        qWarning() << "Cannot register multiple image painters!";
        return;
    }

    mPainter = painter;
    //    QObject::connect(mPainter.get(), &IImagePainter
}

QMLPointer<IImagePainter> ImagePainterManager::getPainter() const
{
    return mPainter;
}
