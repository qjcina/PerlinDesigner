#include "ImagePainterAdapter.h"

#include "ImagePainterManager.h"
#include "Models/IOctavesModel.h"
#include "NoiseGen/IImageData.h"
#include "OctaveSettings/IDataFactory.h"

#include <QAbstractItemModel>
#include <QImage>

ImagePainterAdapter::ImagePainterAdapter(std::shared_ptr<IOctavesModel> octavesModel, std::unique_ptr<IDataFactory>&& dataFactory)
    : mOctavesModel(octavesModel)
    , mDataFactory(std::move(dataFactory))
{
    connect(octavesModel.get(), &QAbstractItemModel::dataChanged, this, &ImagePainterAdapter::updateImage);
    connect(octavesModel.get(), &QAbstractItemModel::rowsInserted, this, &ImagePainterAdapter::updateImage);
    connect(octavesModel.get(), &QAbstractItemModel::rowsRemoved, this, &ImagePainterAdapter::updateImage);
}

void ImagePainterAdapter::updateImage() const
{
    if (!mOctavesModel)
        return;

    if (auto painter = ImagePainterManager::instance()->getPainter()) {
        const auto& octaves = mOctavesModel->getOctaves();
        if (auto imageData = mDataFactory->getData(octaves)) {
            painter->setImage(imageData->getImage());
        }
    }
}
