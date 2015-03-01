#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtDeclarative/QDeclarativeView>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QApplication* app, QWidget *parent = 0);
    ~MainWindow();
    QObject* getEngine();
    QObject* getRoot();

private:
    QDeclarativeView *ui;
};

#endif // MAINWINDOW_H
