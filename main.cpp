#include "mainwindow.h"
#include <QApplication>
#include "logger.h"





int main(int argc, char *argv[])
{

    QApplication a(argc, argv);



#ifdef Q_WS_WIN
    //Logger* log = Logger::instance();
#ifndef QT_NO_DEBUG_OUTPUT
    qInstallMessageHandler(Logger::debugOutput);
#endif
#endif

    qDebug("main!");
    MainWindow w;
    w.show();



    return a.exec();
}


