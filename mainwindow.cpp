#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include "controller.h"
#include "playercontrols.h"
#include "dock.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    // Toggle Signal setzen
    ui->btnPlay->setCheckable(true);
    this->controller = new Controller(this);

    PlayerControls *controls = new PlayerControls(this);
    ui->verticalLayout->addWidget(controls);

    QMediaPlayer* player = this->controller->getPlayer();
    connect(controls,SIGNAL(play()),player, SLOT(play()) );
    connect(player, SIGNAL(stateChanged(QMediaPlayer::State)), controls,SLOT(setState(QMediaPlayer::State)));

   /* QMediaPlaylist *playlist = new QMediaPlaylist;
    playlist->addMedia(QUrl::fromLocalFile("D:\\Musik\\2013\\Kollegah - Paranoia.mp3"));
    playlist->addMedia(QUrl::fromLocalFile("D:\\Musik\\2013\\Tangerine Kitty - Dumb Ways To Die.mp3"));
    playlist->addMedia(QUrl::fromLocalFile("D:\\Musik\\2013\\DCVDNS - Pimp Yannic.mp3"));
    playlist->setCurrentIndex(1);

    player->setPlaylist(playlist); */

    //this->move(100,100);

    Dock *dock = new Dock(this);
    dock->setMainWidget(this);

    this->pw = new playlistWindow(this);
    dock->addWidget(this->pw);
     pw->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnPlay_toggled(bool checked)
{
    qDebug("btnPlay toggled!");


//    if(checked){
//         qDebug("checked true");
//         QMediaPlayer* player = this->controller->getPlayer();

//         //player->State

//         qDebug(QString(player->state()).toUtf8().constData());

//         QMediaPlayer::State s = player->state();

//         if(player->state() == QMediaPlayer::StoppedState){
//             qDebug("stoppedState");
//         }
//         if(player->state() == QMediaPlayer::PausedState){
//             qDebug("PausedState");
//         }
//         player->setMedia(QUrl::fromLocalFile("D:\\Eigene Dateien\\Musik\\2013\\Kollegah - Paranoia.mp3"));
//         player->setVolume(50);
//         player->play();

//         this->ui->btnPlay->setText("Stop");
//    } else {
//     qDebug("checked false");



//     QMediaPlayer* player = this->controller->getPlayer();

//     if(player->state() == QMediaPlayer::StoppedState){
//         qDebug("stoppedState");
//     }

//     player->pause();

//     this->ui->btnPlay->setText("Play");
//    }




    qDebug("Player: play");
}

void MainWindow::on_btnPlay_clicked()
{
    qDebug("btnPlay click!");

    this->pw = new playlistWindow(this);

    pw->move(100,100);
    pw->resize(200,100);
    pw->show();
}
