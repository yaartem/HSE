#include "renderarea.h"

#include <QPainter>
#include <QVector>

RenderArea::RenderArea(QWidget *parent)
    : QWidget(parent)
{

}

void RenderArea::paintEvent(QPaintEvent* /* event */)
{
    QPainter painter(this);

    QVector<QPoint> first= {QPoint(50,50), QPoint(100,125), QPoint(150,50), QPoint(150, 150), QPoint(100, 225), QPoint(50, 150)};
    QVector<QPoint> second= {QPoint(50,60), QPoint(100,135), QPoint(150,60), QPoint(150, 140), QPoint(100, 215), QPoint(50, 140)};
    painter.setBrush(Qt::GlobalColor::blue);
    painter.drawPolygon(QPolygon(first));
    painter.setBrush(Qt::GlobalColor::white);
    painter.drawPolygon(QPolygon(second));
    painter.setBrush(Qt::GlobalColor::yellow);
    painter.drawLine(100,160, 100, 60);
    painter.drawLine(100,160, 100, 260);
    painter.drawLine(100,160, 0, 160);
    painter.drawLine(100,160, 200, 160);
    painter.drawLine(100,160, 30, 90);
    painter.drawLine(100,160, 30, 230);
    painter.drawLine(100,160, 170, 90);
    painter.drawLine(100,160, 170, 230);
    painter.drawEllipse(QPoint(100, 160), 25,25);
}
