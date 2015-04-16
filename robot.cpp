#include "robot.h"

Robot::Robot():
    pos_x(50),
    pos_y(50),
    throttle(0),
    direction(0),
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
    renderer.render(&painter, QRect(-31.0/2, -14, 31, 28));
}

void Robot::AddSpeed(double left, double right)
{
    v_left  += left;
    v_right += right;
}

#define sgn(d) ((0 < (d)) - ((d) < 0))

void Robot::AddDirection(double t, double d)
{
    throttle += t;
    direction += d;

    double mod_dir = throttle >= 0 ? direction : -direction;

    v_left = sgn(throttle - mod_dir) * speed;
    v_right = sgn(throttle + mod_dir) * speed;
}

void Robot::SetSpeed(int v)
{
    speed = v;
}
