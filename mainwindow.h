#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class QDeclarativeView;
class MainWindow : public QMainWindow
{
public:
    explicit MainWindow(QApplication* app, QWidget *parent = 0);
    ~MainWindow();
    QObject* getRoot();
private:
    MainWindow(const MainWindow&);
    MainWindow& operator=(const MainWindow&);
    QDeclarativeView *ui;
};

#endif // MAINWINDOW_H
