#pragma once

#include "IImagePainter.h"
#include "Utils/AbstractSingleton.h"
#include "Utils/QMLPointer.h"

#include <QObject>

class OctaveSettingsEntry;

class ImagePainterManager : public AbstractSingleton<ImagePainterManager> {
public:
    ImagePainterManager();

    void registerPainter(const QMLPointer<IImagePainter>& painter);
    QMLPointer<IImagePainter> getPainter() const;

private:
    QMLPointer<IImagePainter> mPainter;
};
