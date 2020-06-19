#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "GUI/ImagePainter.h"
#include "GUI/ImagePainterAdapter.h"
#include "GUI/ImagePainterManager.h"
#include "Models/OctavesModel.h"
#include "OctaveSettings/OctaveSettingsEntry.h"
#include "OctaveSettings/PerlinDataFactory.h"

int main(int argc, char* argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    auto octavesModel = std::make_shared<OctavesModel>();
    const auto imagePainterAdapter = std::make_unique<ImagePainterAdapter>(octavesModel, std::make_unique<PerlinDataFactory>());

    qmlRegisterType<ImagePainter>("ImagePainter", 1, 0, "ImagePainter");
    qmlRegisterType<OctavesModel>("OctavesModel", 1, 0, "OctavesModel");
    qmlRegisterUncreatableType<IOctavesModel>("OctavesModel", 1, 0, "IOctavesModel", "Interface");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(
        &engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject* obj, const QUrl& objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);

    engine.rootContext()->setContextProperty("OctavesModelInstance", octavesModel.get());
    engine.load(url);

    return app.exec();
}
