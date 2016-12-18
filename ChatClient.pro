#-------------------------------------------------
#
# Project created by QtCreator 2016-11-02T19:54:45
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ChatClient
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialog.cpp \
    tcpclient.cpp

HEADERS  += mainwindow.h \
    dialog.h \
    tcpclient.h

FORMS    += mainwindow.ui \
    dialog.ui
