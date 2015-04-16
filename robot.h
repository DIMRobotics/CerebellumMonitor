#ifndef ROBOT_H
#define ROBOT_H

#include <QSvgRenderer>
#include <QCerebellum/message.h>
#include <QPainter>
#include <qmath.h>

class Robot
{
public:
    Robot();
    void SetPosition(QCerebellum::PositionMessage& m);
    void Draw(QPainter& painter, double scale);
    void AddSpeed(double left, double right);
    void AddDirection(double t, double d);
    double v_left, v_right;
    double throttle, direction;
private:
    double pos_x, pos_y, theta;
    int speed;
    QSvgRenderer renderer;
public:
    void SetSpeed(int v);
};

#endif // ROBOT_H
