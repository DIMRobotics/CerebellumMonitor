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
    if (3.0 / 2 * this->height() <= this->parentWidget()->width() - 20)
    {
        this->resize(3.0 / 2 * this->height(), this->height());
    }
    else
    {
        this->resize(this->parentWidget()->width() - 20, (this->parentWidget()->width() - 20) * 2.0 / 3.0);
    }
}

void GLWidget::keyPressEvent(QKeyEvent* event)
{
    if(event->isAutoRepeat()) return;

    switch(event->key())
    {
    case Qt::Key_W:
        robot.AddDirection(1.0, 0.0);
        break;
    case Qt::Key_S:
        robot.AddDirection(-1.0, 0.0);
        break;
    case Qt::Key_A:
        robot.AddDirection(0.0, 1.0);
        break;
    case Qt::Key_D:
        robot.AddDirection(0.0, -1.0);
        break;
    default:
        return;
    }
    emit speedChanged(QCerebellum::TwistMessage(robot.v_left, robot.v_right, 0.0));
}

void GLWidget::keyReleaseEvent(QKeyEvent* event)
{
    if(event->isAutoRepeat()) return;

    switch(event->key())
    {
    case Qt::Key_W:
        robot.AddDirection(-1.0, 0.0);
        break;
    case Qt::Key_S:
        robot.AddDirection(1.0, 0.0);
        break;
    case Qt::Key_A:
        robot.AddDirection(0.0, -1.0);
        break;
    case Qt::Key_D:
        robot.AddDirection(0.0, 1.0);
        break;
    default:
        return;
    }
    emit speedChanged(QCerebellum::TwistMessage(robot.v_left, robot.v_right, 0.0));
}

void GLWidget::SetSpeed(int v)
{
    robot.SetSpeed(v);
}
