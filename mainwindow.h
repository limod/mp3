#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "controller.h"
#include "playlistwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_btnPlay_toggled(bool checked);

    void on_btnPlay_clicked();

private:
    Ui::MainWindow *ui;
    Controller* controller;
    playlistWindow *pw;
};

#endif // MAINWINDOW_H
