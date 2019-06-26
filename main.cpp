#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickWindow>
#include <QScreen>

#include "obsclient.h"
#include "obsinstance.h"
#include "rpmpackage.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    // Qt text rendering is terrible in low DPI
    // Native text rendering doesn't support high DPI
    if (app.devicePixelRatio() > 1) {
        QQuickWindow::setTextRenderType(QQuickWindow::QtTextRendering);
    } else {
        QQuickWindow::setTextRenderType(QQuickWindow::NativeTextRendering);
    }

    QQmlApplicationEngine engine;

    qmlRegisterType<RPMPackage>("GeekoStore", 1, 0, "RPMPackageModel");

    OBSClient obsClient(OBSInstance::OBS);
    OBSClient pmbsClient(OBSInstance::PMBS);

    engine.rootContext()->setContextProperty("obsClient", &obsClient);
    engine.rootContext()->setContextProperty("pmbsClient", &pmbsClient);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
