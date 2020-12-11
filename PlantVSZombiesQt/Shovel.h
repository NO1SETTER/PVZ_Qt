#ifndef SHOVEL_H
#define SHOVEL_H

#include "Common.h"

class Shovel:public QGraphicsItem
{
private:
    QPixmap shovelPic;
    QPixmap shovelBackPic;
public:
    Shovel();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    void remove(const QPoint& pos);
};

extern QString shovelPath;
extern QString shovelBackPath;
#endif // SHOVEL_H
