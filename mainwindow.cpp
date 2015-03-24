#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

#include <QCerebellum/message.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    socket("tcp://localhost:1234", this),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    updater = new QTimer(this);

    ui->widget->setSocket(&socket);

    connect(updater, SIGNAL(timeout()), this, SLOT(redraw()));
    updater->start(40);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::redraw()
{
    QCerebellum::BinaryIMessage msg("demo");
    socket >> msg;

    ui->lcdNumber->display(QString(msg.getValue()));
    ui->widget->update();
}
