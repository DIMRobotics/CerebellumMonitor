#include "glwidget.h"

#include <QCerebellum/message.h>
//#include <QtMath>

GLWidget::GLWidget(QWidget *parent) :
    QWidget(parent)
{
}

void GLWidget::receivePosition(QCerebellum::PositionMessage m)
{
    pos = m;
    update();
}

void GLWidget::paintEvent(QPaintEvent *)
{
    QPainter imagePainter(this);
    QSvgRenderer renderer(QString(":/map.svg"));
    renderer.render(&imagePainter);
    QPainter robotPainter(this);

        double x = pos.x;
        double y = pos.y;
        double theta = pos.theta * 180 / M_PI;
        robotPainter.resetTransform();
        QBrush brush(QColor(0, 255, 0));
        robotPainter.setBrush(brush);
        robotPainter.scale(this->width() / 300.0, this->height() / 200.0);
        robotPainter.translate(x, y);
        robotPainter.rotate(theta);
        robotPainter.drawRect(-10, -10, 20, 20);

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
