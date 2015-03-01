#include "mainwindow.h"
#include <QDeclarativeContext>
#include <QGraphicsObject>
#include <QDeclarativeEngine>
#include <QApplication>
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

    QObject* appRoot = qobject_cast<QObject*>(app);
    bool res = QObject::connect(getEngine(), SIGNAL(quit()), appRoot, SLOT(quit()));
    if (!res)
    {
        exit(1);
    }
}

MainWindow::~MainWindow()
{
    //Удаляем QML
    delete ui;
}

QObject* MainWindow::getEngine()
{
    return qobject_cast<QObject*>(ui->engine());
}

QObject* MainWindow::getRoot()
{
    return qobject_cast<QObject*>(ui->rootObject());
}
