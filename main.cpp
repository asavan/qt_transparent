#include "singer.h"
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    QQmlApplicationEngine engine;
    QtBassLib qBL;
    engine.load(QUrl("qrc:/main.qml"));
    engine.rootContext()->setContextProperty("sound", &qBL);
    engine.rootContext()->setContextProperty("application", &a);
    return a.exec();
}
