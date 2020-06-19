#include "ImagePainterAdapter.h"

#include "ImagePainterManager.h"
#include "Models/IOctavesModel.h"
#include "NoiseGen/IImageData.h"
#include "OctaveSettings/IDataFactory.h"

#include <QAbstractItemModel>
#include <QtConcurrent/QtConcurrentRun>

namespace {
static const std::array<IOctavesModel::OctavesModelRoles, 3> ACCEPTED_ROLES = {
    IOctavesModel::OctavesModelRoles::Algorihm,
    IOctavesModel::OctavesModelRoles::Color
};
}

ImagePainterAdapter::ImagePainterAdapter(std::shared_ptr<IOctavesModel> octavesModel, std::unique_ptr<IDataFactory>&& dataFactory)
    : mOctavesModel(octavesModel)
    , mDataFactory(std::move(dataFactory))
{
    connect(octavesModel.get(), &QAbstractItemModel::dataChanged, this, [&](const QModelIndex&, const QModelIndex&, const QVector<int> roles) {
        for (const auto& acceptedRole : ACCEPTED_ROLES) {
            if (roles.contains(static_cast<qint32>(acceptedRole))) {
                // Update is only queued when one of ACCEPTED_ROLES is emitted
                this->queueUpdate();
            }
        }
    });

    connect(octavesModel.get(), &QAbstractItemModel::rowsInserted, this, &ImagePainterAdapter::queueUpdate);
    connect(octavesModel.get(), &QAbstractItemModel::rowsRemoved, this, &ImagePainterAdapter::queueUpdate);

    mDelayTimer.setInterval(TIMER_DELAY);
    mDelayTimer.setSingleShot(true);
    mDelayTimer.callOnTimeout(this, &ImagePainterAdapter::updateImage);

    connect(&mImageWatcher, &QFutureWatcher<QImage>::finished, this, &ImagePainterAdapter::setPainterImage);
    connect(&mImageWatcher, &QFutureWatcher<QImage>::finished, octavesModel.get(), &IOctavesModel::updateAlgorithmValid);
}

void ImagePainterAdapter::updateImage()
{
    static QFuture<QImage> image;
    if (image.isRunning())
        image.cancel();
    image = QtConcurrent::run(this, &ImagePainterAdapter::getImage);
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
