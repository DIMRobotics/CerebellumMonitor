#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QWidget>
#include <QtGui>
#include <QtSvg/QSvgRenderer>
#include <QApplication>
#include <QPainter>

#include <QCerebellum/qtcerebellum.h>

class GLWidget : public QWidget
{
    Q_OBJECT

    QCerebellum::Socket *socket;

public:
    explicit GLWidget(QWidget *parent = 0);
    void setSocket(QCerebellum::Socket *s) { socket = s; }
    virtual void paintEvent(QPaintEvent * e);
    virtual void resizeEvent(QResizeEvent *);

signals:

public slots:

};

#endif // GLWIDGET_H
