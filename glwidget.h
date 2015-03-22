#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QWidget>
#include <QtGui>
#include <QtSvg/QSvgRenderer>
#include <QApplication>
#include <QPainter>

class GLWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = 0);
    virtual void paintEvent(QPaintEvent * e);
    virtual void resizeEvent(QResizeEvent *);

signals:

public slots:

};

#endif // GLWIDGET_H
