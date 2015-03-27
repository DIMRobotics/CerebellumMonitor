#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QWidget>
#include <QtGui>
#include <QtSvg/QSvgRenderer>
#include <QApplication>
#include <QPainter>

#include <QCerebellum/msgtypes.h>

class GLWidget : public QWidget
{
    Q_OBJECT

    QCerebellum::PositionMessage pos;

public:
    explicit GLWidget(QWidget *parent = 0);
    virtual void paintEvent(QPaintEvent * e);
    virtual void resizeEvent(QResizeEvent *);

signals:

public slots:
    void receivePosition(QCerebellum::PositionMessage m);
};

#endif // GLWIDGET_H
