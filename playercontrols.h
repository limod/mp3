#ifndef PLAYERCONTROLS_H
#define PLAYERCONTROLS_H

//#include <QWidget>
#include <QMediaPlayer>
#include <QPushButton>

class PlayerControls : public QWidget {

     Q_OBJECT
public:
    PlayerControls(QWidget* parent = 0);
    QMediaPlayer::State state() const;


private:
    QPushButton *btnPlay;
    QPushButton *btnNext;
    QPushButton *btnPrevious;

    QMediaPlayer::State playerState;

private slots:
    void playClicked();
    void pauseClicked();
    void setState(QMediaPlayer::State state);

signals:
    void play();
    void pause();
};

#endif // PLAYERCONTROLS_H
