#include "robot.h"

Robot::Robot():
    pos_x(50),
    pos_y(50),
    theta(0),
    renderer(QString(":/robot.svg"))
{}

void Robot::SetPosition(QCerebellum::PositionMessage& m)
{
    pos_x = m.x;
    pos_y = m.y;
    theta = m.theta * 180 / M_PI;
}

void Robot::Draw(QPainter& painter, double scale)
{
    painter.resetTransform();
    painter.scale(scale, scale);
    painter.translate(pos_x, pos_y);
    painter.rotate(theta);
    renderer.render(&painter, QRect(-10, -10, 20, 20));
}
