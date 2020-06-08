#pragma once

#include <QObject>
#include <memory>

#include "OctaveSettings/IDataFactory.h"

class IOctavesModel;

class ImagePainterAdapter : public QObject {
    Q_OBJECT
public:
    ImagePainterAdapter(std::shared_ptr<IOctavesModel> octavesModel, std::unique_ptr<IDataFactory>&& dataFactory);

private:
    void updateImage() const;

    std::shared_ptr<IOctavesModel> mOctavesModel;
    std::unique_ptr<IDataFactory> mDataFactory;
};
