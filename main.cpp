#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQuickItem>
#include <QDebug>

#include <QImage>
#include <QDir>

//returns 0 on success
int imageResize() {
    QImage image;

    if (!image.load("imag/not0.png")) {
        qWarning("Failed to load the image.");
        return 1;
    }
    QSize newSize(256, 256);
    QImage resizedImage = image.scaled(newSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);

    if (!resizedImage.save("thmb/not0.jpg", "JPG")) {
        qWarning("Failed to save the image.");
        return 1;
    }
    return 0;
}

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QDir dir(QDir::currentPath());
    dir.cdUp();
    dir.cd("mini-text-editor-qt");
    QDir::setCurrent(dir.path());

    //imageResize();

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url("qrc:/main.qml");
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
