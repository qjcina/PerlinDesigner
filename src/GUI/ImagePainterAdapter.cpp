#include "ImagePainterAdapter.h"

#include "ImagePainterManager.h"
#include "Models/IOctavesModel.h"
#include "NoiseGen/IImageData.h"
#include "OctaveSettings/IDataFactory.h"

#include <QAbstractItemModel>
#include <QtConcurrent/QtConcurrentRun>

ImagePainterAdapter::ImagePainterAdapter(std::shared_ptr<IOctavesModel> octavesModel, std::unique_ptr<IDataFactory>&& dataFactory)
    : mOctavesModel(octavesModel)
    , mDataFactory(std::move(dataFactory))
{
    connect(octavesModel.get(), &QAbstractItemModel::dataChanged, this, &ImagePainterAdapter::queueUpdate);
    connect(octavesModel.get(), &QAbstractItemModel::rowsInserted, this, &ImagePainterAdapter::queueUpdate);
    connect(octavesModel.get(), &QAbstractItemModel::rowsRemoved, this, &ImagePainterAdapter::queueUpdate);

    mDelayTimer.setInterval(TIMER_DELAY);
    mDelayTimer.setSingleShot(true);
    mDelayTimer.callOnTimeout(this, &ImagePainterAdapter::updateImage);

    connect(&mImageWatcher, &QFutureWatcher<QImage>::finished, this, &ImagePainterAdapter::setPainterImage);
}

void ImagePainterAdapter::updateImage()
{
    QFuture<QImage> image = QtConcurrent::run(this, &ImagePainterAdapter::getImage);
    mImageWatcher.setFuture(image);
}

void ImagePainterAdapter::queueUpdate()
{
    mDelayTimer.start();
}

QImage ImagePainterAdapter::getImage() const
{
    if (!mOctavesModel)
        return QImage();

    const auto& octaves = mOctavesModel->getOctaves();
    if (auto imageData = mDataFactory->getData(octaves)) {
        return imageData->getImage();
    }
    return QImage();
}

void ImagePainterAdapter::setPainterImage() const
{
    if (auto painter = ImagePainterManager::instance()->getPainter()) {
        QImage image = mImageWatcher.future().result();
        painter->setImage(std::move(image));
    }
}
