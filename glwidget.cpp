#include "glwidget.h"

//#include <QtMath>

GLWidget::GLWidget(QWidget *parent) :
    QWidget(parent)
{
}

void GLWidget::receivePosition(QCerebellum::PositionMessage m)
{
    robot.SetPosition(m);
    update();
}

void GLWidget::paintEvent(QPaintEvent *)
{
    QPainter imagePainter(this);
    QSvgRenderer imageRenderer(QString(":/map.svg"));
    imageRenderer.render(&imagePainter);

    QPainter robotPainter(this);
    robot.Draw(robotPainter, this->width() / 300.0);
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
