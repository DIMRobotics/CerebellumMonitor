#include "socketthread.h"

#include <QDebug>

SocketThread::SocketThread(const QString &address, int posInt, int odInt, QObject *parent) :
    QObject(parent),
    socket(address, this),
    posInterval(posInt),
    odInterval(odInt)
{
    pos_updater = new QTimer();
    odetect_updater = new QTimer();

    connect(pos_updater, SIGNAL(timeout()), this, SLOT(getPosition()));
    connect(odetect_updater, SIGNAL(timeout()), this, SLOT(getODetect()));

    pos_updater->setInterval(posInterval);
    odetect_updater->setInterval(odInterval);

    pos_updater->start();
    odetect_updater->start();
}

SocketThread::~SocketThread()
{
    delete pos_updater;
    delete odetect_updater;
}

void SocketThread::getPosition()
{
    QCerebellum::PositionMessage m;
    socket >> m;
    emit positionReceived(m);
}

void SocketThread::getODetect()
{
    QCerebellum::ODetectMessage m;
    socket >> m;
    emit odetectReceived(m);
}

void SocketThread::sendTwist(QCerebellum::TwistMessage m)
{
    socket << m;
}
