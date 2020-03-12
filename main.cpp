#include "singer.h"
#include <QApplication>
#include <QtQml/QQmlEngine>
#include <QtQuick/QQuickView>
#include <QQuickItem>
#include <QQmlContext>
#include <iostream>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QQuickView * ui = new QQuickView;
    ui->setSource(QUrl("qrc:/main.qml"));

    ui->setSurfaceType(QSurface::OpenGLSurface);

    QSurfaceFormat format;
    format.setAlphaBufferSize(8);
    format.setRenderableType(QSurfaceFormat::OpenGL);

    ui->setFormat(format);
    ui->setColor(QColor(Qt::transparent));
    ui->setClearBeforeRendering(true);
    ui->setFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::Tool);
    ui->rootContext()->setContextProperty("mainwindow", ui);


    QtBassLib qBL;
    QObject *root = ui->rootObject();

    bool res = QObject::connect(root, SIGNAL(dataRequired(int)), &qBL, SLOT(playMusic(int)));
    if (!res)
    {
        std::cout << "No music" << std::endl;
    }
    res = QObject::connect(ui->engine(), SIGNAL(quit()), &a, SLOT(quit()));
    if (!res)
    {
        std::cout << "No quit" << std::endl;
    }
    ui->show();
    return a.exec();
}
