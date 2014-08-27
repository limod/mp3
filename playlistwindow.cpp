#include "playlistwindow.h"
#include "ui_playlistwindow.h"
#include <QMoveEvent>

playlistWindow::playlistWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::playlistWindow),
    isDocked(false)
{

    ui->setupUi(this);

}

playlistWindow::~playlistWindow()
{
    delete ui;
}

void playlistWindow::moveEvent(QMoveEvent * event){
    QPoint childPosition = event->pos();
    int frameWidth = this->frameGeometry().width() - this->width();
    event->accept();

    //position.x()
    //qDebug(QString::number(position.x()).toWCharArray());

    //QWidget *foo =  this->parent();
    QPoint parentPosition = this->parentWidget()->pos();

    // Playlist rechte Seite zu MainWindows linke Seite
    int diffRight = parentPosition.x() - childPosition.x() - this->width() -16;

     qDebug("child: %d, parent: %d, diff: %d", childPosition.x(), parentPosition.x(), diffRight);

    if( diffRight > 5 && diffRight < 30 && !isDocked){


        isDocked = true;
//        this->grabMouse();
//        this->releaseMouse();

        this->move(childPosition.x() + diffRight, childPosition.y());
        qDebug("move window to: %d, %d",childPosition.x() + diffRight, childPosition.y());
        // this->move(event->oldPos().x() , event->oldPos().y());
       // this->move(400,600);
    } else {
        // Erst bewegen wenn DiffRight < 30
        if(diffRight > 30){
            isDocked = false;
        }
    }

}
