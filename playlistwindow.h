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
    //void moveEvent(QMoveEvent * event);
   // virtual void paintEvent (QPaintEvent *);
    virtual void resizeEvent (QResizeEvent *);
    virtual void mouseMoveEvent (QMouseEvent *);
    virtual void mousePressEvent (QMouseEvent *);
    virtual void mouseReleaseEvent (QMouseEvent *);
    virtual void changeEvent (QEvent*);
    virtual void closeEvent (QCloseEvent*);
    virtual void keyPressEvent (QKeyEvent*);


private:
    Ui::playlistWindow *ui;
    bool isDocked;
    int xPos;
    int yPos;
    bool m_resize;
    bool m_update;
    int m_ratio;
    int m_height;
    bool m_shaded;




};

#endif // PLAYLISTWINDOW_H
