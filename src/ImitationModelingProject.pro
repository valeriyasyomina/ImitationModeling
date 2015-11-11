#-------------------------------------------------
#
# Project created by QtCreator 2015-11-10T17:39:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ImitationModelingProject
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Memory/Memory.cpp

HEADERS  += mainwindow.h \
    Queue/QueueElement.h \
    Queue/Queue.h \
    Memory/Memory.h

FORMS    += mainwindow.ui
