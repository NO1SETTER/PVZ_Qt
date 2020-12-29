#ifndef SUN_H
#define SUN_H
#include"Common.h"
class Sun:public QGraphicsItem
{
public:
    Sun();
    Sun(int _x,int _y);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void advance(int phase) override;
private:
    QMovie* sunGif;
    int x,y;
    int width,height;

    bool falling;
    bool dead = 0;
    int targetY;

};

#endif // SUN_H
