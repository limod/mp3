#ifndef LOGGER_H
#define LOGGER_H
//#include <QDebug>
#include <QMutex>


class Logger{

private:
//    Logger() {}

//    Logger(const Logger &);
//    Logger& operator=(const Logger &);

//    static Logger* m_Instance;

public:
//    static Logger* instance() {

//        static QMutex mutex;

//        if (!m_Instance)
//        {
//            mutex.lock();

//            if (!m_Instance)
//                m_Instance = new Logger;

//            mutex.unlock();
//        }

//        return m_Instance;
//    }

    static void debugOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg);



};


#endif // LOGGER_H
