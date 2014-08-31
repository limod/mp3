#-------------------------------------------------
#
# Project created by QtCreator 2014-08-22T10:41:01
#
#-------------------------------------------------

QT       += core gui \
        multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mp3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    logger.cpp \
    controller.cpp \
    playercontrols.cpp \
    playlistwindow.cpp \
    dock.cpp

HEADERS  += mainwindow.h \
    logger.h \
    controller.h \
    playercontrols.h \
    playlistwindow.h \
    dock.h

FORMS    += mainwindow.ui \
    playlistwindow.ui

CONFIG += console

DEFINES -= QT_NO_DEBUG_OUTPUT
