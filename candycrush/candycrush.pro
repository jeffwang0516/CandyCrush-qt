#-------------------------------------------------
#
# Project created by QtCreator 2015-06-19T20:40:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = candycrush
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    candy.cpp \
    candy_1.cpp \
    candy_2.cpp \
    candy_3.cpp \
    candy_4.cpp \
    gencandy.cpp \
    point.cpp \
    steps.cpp \
    stars.cpp \
    windowend.cpp \
    clearblock.cpp \
    horizontalchk.cpp \
    verticalchk.cpp

HEADERS  += mainwindow.h \
    candy.h \
    candy_1.h \
    candy_2.h \
    candy_3.h \
    candy_4.h \
    gencandy.h \
    point.h \
    steps.h \
    stars.h \
    windowend.h \
    clearblock.h \
    horizontalchk.h \
    verticalchk.h

FORMS    += mainwindow.ui \
    windowend.ui

RESOURCES += \
    pic.qrc
