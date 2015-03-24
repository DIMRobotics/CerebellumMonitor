#include "glwidget.h"

#include <QCerebellum/message.h>
#include <QtMath>

GLWidget::GLWidget(QWidget *parent) :
    QWidget(parent),
    socket(0)
{
}


void GLWidget::paintEvent(QPaintEvent *)
{
    QPainter imagePainter(this);
    QSvgRenderer renderer(QString(":/map.svg"));
    renderer.render(&imagePainter);
    QPainter robotPainter(this);
    if(socket)
    {
        QCerebellum::PositionMessage msg;
        qDebug() << msg.getName();

        *socket >> msg;
        double x = msg.x;
        double y = msg.y;
        double theta = msg.theta * 180 / M_PI;
        qDebug() << "X: " << x << "Y: " << y << "Theta: " << theta;
        robotPainter.resetTransform();
        QBrush brush(QColor(0, 255, 0));
        robotPainter.setBrush(brush);
        robotPainter.rotate(theta);
        robotPainter.drawRect(x, y, 20, 20);
    }
}

void GLWidget::resizeEvent(QResizeEvent *)
{
    if (3.0 / 2 * this->height() <= this->parentWidget()->width() - 110)
    {
        this->resize(3.0 / 2 * this->height(), this->height());
    }
    else
    {
        this->resize(this->parentWidget()->width() - 110, (this->parentWidget()->width() - 110) * 2.0 / 3.0);
    }
}
