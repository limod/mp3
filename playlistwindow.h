#ifndef PLAYLISTWINDOW_H
#define PLAYLISTWINDOW_H

#include <QMainWindow>

namespace Ui {
class playlistWindow;
}

class playlistWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit playlistWindow(QWidget *parent = 0);
    ~playlistWindow();

protected:
    void moveEvent(QMoveEvent * event);

private:
    Ui::playlistWindow *ui;
    bool isDocked;





};

#endif // PLAYLISTWINDOW_H
