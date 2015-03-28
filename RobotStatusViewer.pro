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
    glwidget.cpp \
    socketthread.cpp

HEADERS  += mainwindow.h \
    glwidget.h \
    socketthread.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    map.svg

RESOURCES += \
    images.qrc

#CONFIG += console

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../Загрузки/libqtcerebellum-master/release/ -lqtcerebellum
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../Загрузки/libqtcerebellum-master/debug/ -lqtcerebellum
else:unix: LIBS += -L$$PWD/../Загрузки/libqtcerebellum-master/ -lqtcerebellum

INCLUDEPATH += $$PWD/../Загрузки/libqtcerebellum-master/include
DEPENDPATH += $$PWD/../Загрузки/libqtcerebellum-master/include
