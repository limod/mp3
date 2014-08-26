#include "logger.h"

#include <QTextBrowser>

//Logger* Logger::m_Instance = 0;


void Logger::debugOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg){
    static QTextBrowser* browser = new QTextBrowser();
    browser->move(200,200);
    browser->setWindowTitle("Debug-Fenster");

    browser->show();

    switch(type){
        case QtDebugMsg:
            browser->append(QString("Debug: %1").arg(msg));
            break;
        case QtWarningMsg:
            browser->append(QString("Warning: %1").arg(msg));
            break;
        case QtCriticalMsg:
            browser->append(QString("Critical: %1").arg(msg));
            break;
        case QtFatalMsg:
            browser->append(QString("Fatal: %1").arg(msg));
            break;
    }
}


