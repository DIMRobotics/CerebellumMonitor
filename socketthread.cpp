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

    qDebug() << Q_FUNC_INFO;
}

SocketThread::~SocketThread()
{
    qDebug() << Q_FUNC_INFO;
    delete pos_updater;
    delete odetect_updater;
}

void SocketThread::getPosition()
{

    QCerebellum::PositionMessage m;
    socket >> m;

    // Slow down timer if server is unavailable
    if (!socket.serverOnline()) {
        pos_updater->setInterval(5000);
        odetect_updater->stop();
        return;
    } else {
        pos_updater->setInterval(posInterval);
        odetect_updater->setInterval(odInterval);
        odetect_updater->start();
    }

    emit positionReceived(m);
}

void SocketThread::getODetect()
{
    QCerebellum::ODetectMessage m;
    socket >> m;

    // Slow down timer if server is unavailable
    if (!socket.serverOnline()) {
        pos_updater->setInterval(5000);
        odetect_updater->stop();
        return;
    } else {
        pos_updater->setInterval(posInterval);
        odetect_updater->setInterval(odInterval);
        odetect_updater->start();
    }

    emit odetectReceived(m);
}

void SocketThread::sendTwist(QCerebellum::TwistMessage m)
{
    socket << m;
}

void SocketThread::stop()
{
    qDebug() << "Stop polling thread";
    pos_updater->stop();
    odetect_updater->stop();
}
