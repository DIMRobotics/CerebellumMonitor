#include "glwidget.h"

GLWidget::GLWidget(QWidget *parent) :
    QWidget(parent)
{
}


void GLWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QSvgRenderer renderer(QString(":/map.svg"));
    renderer.render(&painter);
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
