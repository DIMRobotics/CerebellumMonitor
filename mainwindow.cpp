#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

#include <QCerebellum/message.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    poller = new QThread(this);
    s = new SocketThread("tcp://localhost:1234", 40, 40); /// TODO: replace it with configuration constant
    s->moveToThread(poller);

    connect(s, SIGNAL(positionReceived(QCerebellum::PositionMessage)), ui->widget, SLOT(receivePosition(QCerebellum::PositionMessage)));
    connect(poller, SIGNAL(finished()), poller, SLOT(deleteLater()));
    connect(this, SIGNAL(closed()), poller, SLOT(quit()));

    poller->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *e)
{
    Q_UNUSED(e);
    emit closed();
    poller->wait();
}
