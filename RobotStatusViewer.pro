#-------------------------------------------------
#
# Project created by QtCreator 2015-03-22T12:32:53
#
#-------------------------------------------------

QT       += core gui svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RobotStatusViewer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    glwidget.cpp

HEADERS  += mainwindow.h \
    glwidget.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    map.svg

RESOURCES += \
    images.qrc

#CONFIG += console

unix|win32: LIBS += -L$$PWD/../libqtcerebellum/build/ -lqtcerebellum

INCLUDEPATH += $$PWD/../libqtcerebellum/include
DEPENDPATH += $$PWD/../libqtcerebellum/include
