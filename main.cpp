#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickWindow>
#include <QScreen>

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
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
