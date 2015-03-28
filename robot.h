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
private:
    double pos_x, pos_y, theta;
    QSvgRenderer renderer;
};

#endif // ROBOT_H
