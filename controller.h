#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QMediaPlayer>

class Controller{

private:
    QMediaPlayer* player;

public:
    Controller(QObject* parent);

    QMediaPlayer* getPlayer(){
        return this->player;
    }


};

#endif // CONTROLLER_H
