#include "controller.h"

Controller::Controller(QObject* parent){
    this->player= new QMediaPlayer(parent);
}
