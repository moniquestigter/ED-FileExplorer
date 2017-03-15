#-------------------------------------------------
#
# Project created by QtCreator 2017-03-04T11:03:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = File-Explorer-ED
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    fsu.cpp \
    folder.cpp \
    lista.cpp \
    archivotext.cpp \
    archivo.cpp \
    treeitem.cpp \
    treemodel.cpp

HEADERS  += mainwindow.h \
    fsu.h \
    folder.h \
    lista.h \
    archivotext.h \
    archivo.h \
    treeitem.h \
    treemodel.h

FORMS    += mainwindow.ui

RESOURCES += \
    iconos.qrc
