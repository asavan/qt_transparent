#include "singer.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

int main(int argc, char* argv[])
{
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication a(argc, argv);
    QQmlApplicationEngine engine;
    QtBassLib qBL;
    engine.load(QUrl("qrc:/main.qml"));
    engine.rootContext()->setContextProperty("sound", &qBL);
    engine.rootContext()->setContextProperty("application", &a);
    return a.exec();
}
