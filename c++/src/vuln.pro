#-------------------------------------------------
#
# Project created by QtCreator 2014-09-13T14:37:39
#
#-------------------------------------------------

QT       += core gui webkit webkitwidgets network xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = vuln
TEMPLATE = app

CONFIG += static

SOURCES += main.cpp\
        mainwindow.cpp \
    dialog.cpp

HEADERS  += mainwindow.h \
    dialog.h

FORMS    += mainwindow.ui \
    dialog.ui

RC_FILE += config.rc
