#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "nfccontrol.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    QObject *item = engine.rootObjects().at(0);
    NFCControl controllerNFC;
    QObject::connect(item, SIGNAL(readSignal()),
                    &controllerNFC, SLOT(enableRead()));

    QObject::connect(item, SIGNAL(cancelReadWrite()),
                    &controllerNFC, SLOT(cancelOperation()));

    QObject::connect(item, SIGNAL(writeData(QString)),
                    &controllerNFC, SLOT(writeData(QString)));

    return app.exec();
}
