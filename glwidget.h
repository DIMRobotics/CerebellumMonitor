#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QWidget>
#include <QtGui>
#include <QtSvg/QSvgRenderer>
#include <QApplication>
#include <QPainter>
#include <robot.h>

#include <QCerebellum/msgtypes.h>

class GLWidget : public QWidget
{
    Q_OBJECT

    QCerebellum::PositionMessage pos;

public:
    Robot robot;
    explicit GLWidget(QWidget *parent = 0);
    virtual void paintEvent(QPaintEvent * e);
    virtual void resizeEvent(QResizeEvent *);
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);

signals:
    void speedChanged(QCerebellum::TwistMessage message);
public slots:
    void receivePosition(QCerebellum::PositionMessage m);
    void SetSpeed(int v);
};

#endif // GLWIDGET_H
