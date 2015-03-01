#include "mainwindow.h"
#include "singer.h"
#include <QApplication>
#include <QDir>
#include <QByteArray>
#include <QDebug>

int main(int argc, char *argv[])
{
    // QCoreApplication::addLibraryPath(QCoreApplication::applicationDirPath() + QDir::separator() + "release");
    QApplication a(argc, argv);
    // QCoreApplication::addLibraryPath(QCoreApplication::applicationDirPath() + QDir::separator() + "release");
    a.addLibraryPath(a.applicationDirPath() + QDir::separator() + "\release");
    a.addLibraryPath("C:\Develop\qmltest\release");
    qDebug() << a.libraryPaths().join(',');
    MainWindow w(&a);
    w.show();

    MyClass myClass;
    bool res = QObject::connect(w.getRoot(), SIGNAL(dataRequired(int)), &myClass, SLOT(getData(int)));
    if (!res)
    {
        exit(1);
    }
    return a.exec();
}
