#include "playlistwindow.h"
#include "ui_playlistwindow.h"
#include <QMoveEvent>
#include <QMouseEvent>
#include "dock.h"

playlistWindow::playlistWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::playlistWindow),
    isDocked(false)
{

    ui->setupUi(this);
    this->xPos = 100;
    this->yPos = 200;

}

playlistWindow::~playlistWindow()
{
    delete ui;
}


void playlistWindow::resizeEvent (QResizeEvent *)
{
    //updatePositions();
}

void playlistWindow::mousePressEvent (QMouseEvent *e)
{
    Q_UNUSED(e);
//    if (m_resizeWidget->underMouse())
//    {
//        m_resize = true;
//        setCursor (m_skin->getCursor (Skin::CUR_PSIZE));
//    }
//    else
//        m_resize = false;
}

void playlistWindow::mouseMoveEvent (QMouseEvent *e)
{
    if (m_resize)
    {
#ifdef Q_OS_WIN
        int sx = (width()-275) /25;
        int sy = (height()-116) /29;
    if(width() < e->x() - 14)
           sx++;
    else if(width() > e->x() + 14)
           sx--;
        if(height() < e->y() - 14)
           sy++;
        else if(height() > e->y() + 14)
           sy--;
        resize (275+25*sx,116+29*sy);
#else
#ifdef Q_WS_X11
        //avoid right corner moving during resize
        if(layoutDirection() == Qt::RightToLeft)
            WindowSystem::revertGravity(winId());
#endif
        resize (e->x() +25, e->y() +25);
#endif
    }
}

void playlistWindow::mouseReleaseEvent (QMouseEvent *)
{
    //setCursor (m_skin->getCursor (Skin::CUR_PNORMAL));
    /*if (m_resize)
        m_listWidget->updateList();*/
    m_resize = false;
    Dock::instance()->updateDock();
}

void playlistWindow::closeEvent (QCloseEvent *e)
{
   // writeSettings();
    if (e->spontaneous ())
        parentWidget()->close();
}



void playlistWindow::changeEvent (QEvent * event)
{
//    if (event->type() == QEvent::ActivationChange)
//    {
//        m_titleBar->setActive (isActiveWindow());
//    }
}

void playlistWindow::keyPressEvent (QKeyEvent *ke)
{
//    m_keyboardManager->handleKeyPress (ke);
}

//void playlistWindow::moveEvent(QMoveEvent * event){
//    // Get positions of the two QMainWindows
//    QPoint childPosition = event->pos();
//    int frameWidth = this->frameGeometry().width() - this->width();
//    QPoint parentPosition = this->parentWidget()->pos();
//    // Calculate distance to parent Window
//    int diffRight = parentPosition.x() - childPosition.x() - this->width() - frameWidth;

//     qDebug("child: %d, parent: %d, diff: %d", childPosition.x(), parentPosition.x(), diffRight);

//    // If it is near, move it to the frame of the parent window
//    if( diffRight > 5 && diffRight < 30 && !isDocked){


//        isDocked = true;
//        this->xPos = childPosition.x() + diffRight;
//        this->yPos = childPosition.y();
////        this->grabMouse();
////        this->releaseMouse();

//        this->move(childPosition.x() + diffRight, childPosition.y());
//        qDebug("move window to: %d, %d",childPosition.x() + diffRight, childPosition.y());

//       // this->move(event->oldPos().x() , event->oldPos().y());
//       // this->move(400,600);
//    } else {
//        // Erst bewegen wenn DiffRight < 30
//        if(diffRight > 30){
//            isDocked = false;
//        }
//    }

//}
