#ifndef PAUSEBUTTON_H
#define PAUSEBUTTON_H
#include"Common.h"

class PauseButton:public QGraphicsItem
{
public:
    PauseButton(QTimer* t1,QTimer* t2,QTimer* t3);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    bool isPause();
private:
    QPixmap pix;
    bool PauseState;
    QTimer* timer1;
    QTimer* timer2;
    QTimer* timer3;
};

#endif // PAUSEBUTTON_H
