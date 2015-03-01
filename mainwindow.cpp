#include "mainwindow.h"
#include <QDeclarativeContext>
#include <QGraphicsObject>
#include <QDeclarativeEngine>
#include <QApplication>
#include <QtDeclarative/QDeclarativeView>

MainWindow::MainWindow(QApplication* app, QWidget *parent) :
    QMainWindow(parent)
{
    //Эти две строчки позволят форме становиться прозрачной
    setAttribute(Qt::WA_TranslucentBackground);
    setStyleSheet("background:transparent;");

    //Этот код уберет все внешние элементы формы
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);

    //Включаем наш QML
    ui = new QDeclarativeView;
    ui->setSource(QUrl("qrc:/main.qml"));
    ui->setResizeMode(QDeclarativeView::SizeRootObjectToView);

    setCentralWidget(ui);
    ui->rootContext()->setContextProperty("mainwindow", this);

    bool res = QObject::connect(ui->engine(), SIGNAL(quit()), app, SLOT(quit()));
    if (!res)
    {
        // exit(1);
    }
}

MainWindow::~MainWindow()
{
    //Удаляем QML
    delete ui;
}

QObject* MainWindow::getRoot()
{
    return ui->rootObject();
}
