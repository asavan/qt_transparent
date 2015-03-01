#include "mainwindow.h"
#include "singer.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // QCoreApplication::addLibraryPath(QCoreApplication::applicationDirPath() + QDir::separator() + "release");
    MainWindow w(&a);

    QtBassLib qBL;
    bool res = QObject::connect(w.getRoot(), SIGNAL(dataRequired(int)), &qBL, SLOT(playMusic(int)));
    if (!res)
    {
        std::cout << "No music" << std::endl;
    }

    w.show();
    return a.exec();
}
