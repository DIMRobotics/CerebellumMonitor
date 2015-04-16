#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

#include <QCerebellum/message.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    addr("tcp://localhost:1235"),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    poller = new QThread(this);
    s = new SocketThread("tcp://localhost:1235", 1, 2); /// TODO: replace it with configuration constant
    s->moveToThread(poller);

    connect(s, SIGNAL(positionReceived(QCerebellum::PositionMessage)), ui->widget, SLOT(receivePosition(QCerebellum::PositionMessage)));
    connect(poller, SIGNAL(finished()), poller, SLOT(deleteLater()));
    connect(this, SIGNAL(closed()), s, SLOT(stop()));
    connect(this, SIGNAL(closed()), poller, SLOT(quit()));
    connect(ui->actionOptions, SIGNAL(triggered()), this, SLOT(setAddress()));
    connect(ui->widget, SIGNAL(speedChanged(QCerebellum::TwistMessage)), s, SLOT(sendTwist(QCerebellum::TwistMessage)));
    connect(ui->spinBox, SIGNAL(valueChanged(int)), ui->widget, SLOT(SetSpeed(int)));

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
    poller->wait(1000);
    if (poller->isRunning())
        poller->terminate(); // TODO: remove this bullshit
}

void MainWindow::setAddress()
{
    bool ok;
            QString text = QInputDialog::getText(this, "Options", "Address:", QLineEdit::Normal, addr, &ok);
            if (ok && !text.isEmpty())
            {
                addr = text;
                qDebug() << addr;
            }
}

void MainWindow::keyPressEvent(QKeyEvent* event)
{
    ui->widget->keyPressEvent(event);
}

void MainWindow::keyReleaseEvent(QKeyEvent* event)
{
    ui->widget->keyReleaseEvent(event);
}
