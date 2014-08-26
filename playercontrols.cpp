#include "playercontrols.h"
#include <QHBoxLayout>

PlayerControls::PlayerControls(QWidget *parent) : QWidget(parent){
    btnPlay = new QPushButton(this);
    btnPlay->setText("Play");
    connect(btnPlay, SIGNAL(clicked()),SLOT(playClicked()));


    btnNext = new QPushButton(this);
    btnNext->setText("Next");

    btnPrevious = new QPushButton(this);
    btnPrevious->setText("Previous");


    QBoxLayout *layout = new QHBoxLayout;
    layout->setMargin(0);
    layout->addWidget(btnPrevious);
    layout->addWidget(btnPlay);
    layout->addWidget(btnNext);
    setLayout(layout);
}

void PlayerControls::playClicked(){
    emit play();
}

void PlayerControls::pauseClicked(){
    emit pause();
}

void PlayerControls::setState(QMediaPlayer::State state){
    this->playerState = state;
}

QMediaPlayer::State PlayerControls::state() const
{
    return playerState;
}

