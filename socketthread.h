#ifndef SOCKETTHREAD_H
#define SOCKETTHREAD_H

#include <QObject>
#include <QThread>
#include <QTimer>

#include <QCerebellum/qtcerebellum.h>
#include <QCerebellum/message.h>

class SocketThread : public QObject
{
    Q_OBJECT

    QCerebellum::Socket socket;
    QTimer *pos_updater;
    QTimer *odetect_updater;
    QThread *poller;

    int posInterval;
    int odInterval;

public:
    explicit SocketThread(const QString &address, int posInt = 25, int odInt = 25, QObject *parent = 0);
    ~SocketThread();

signals:
    void positionReceived(QCerebellum::PositionMessage m);
    void odetectReceived(QCerebellum::ODetectMessage m);

public slots:
    void sendTwist(QCerebellum::TwistMessage m);

private slots:
    void getPosition();
    void getODetect();
};

#endif // SOCKETTHREAD_H
