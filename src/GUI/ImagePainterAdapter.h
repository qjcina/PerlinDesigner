#pragma once

#include <QFutureWatcher>
#include <QImage>
#include <QObject>
#include <QTimer>
#include <memory>

#include "OctaveSettings/IDataFactory.h"

class IOctavesModel;

class ImagePainterAdapter : public QObject {
    Q_OBJECT
    static constexpr const uint32_t TIMER_DELAY = 100;

public:
    ImagePainterAdapter(std::shared_ptr<IOctavesModel> octavesModel, std::unique_ptr<IDataFactory>&& dataFactory);

private:
    void updateImage();
    void queueUpdate();
    QImage getImage() const;
    void setPainterImage() const;

    void updateProgressValue(qint32 value) const;

    std::shared_ptr<IOctavesModel> mOctavesModel;
    std::unique_ptr<IDataFactory> mDataFactory;

    QFutureWatcher<QImage> mImageWatcher;

    QTimer mDelayTimer;
};
