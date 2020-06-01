#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "GUI/ImagePainter.h"
#include "Models/OctavesModel.h"
#include "OctaveSettings/OctaveSettingsEntry.h"

int main(int argc, char* argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<ImagePainter>("ImagePainter", 1, 0, "ImagePainter");
    qmlRegisterType<OctavesModel>("OctavesModel", 1, 0, "OctavesModel");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(
        &engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject* obj, const QUrl& objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);

    engine.rootContext()->setContextProperty("OctavesModelInstance", new OctavesModel());
    engine.load(url);

    return app.exec();
}
