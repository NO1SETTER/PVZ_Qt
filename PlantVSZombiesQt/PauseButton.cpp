#include"PauseButton.h"

PauseButton::PauseButton(QTimer* t1,QTimer* t2,QTimer* t3)
{
    PauseState = 0;
    pix = QPixmap("images/pauseButton.jpeg");
    timer1 = t1;
    timer2 = t2;
    timer3 = t3;
}

QRectF PauseButton::boundingRect() const
{
    return QRectF(500,0,60,60);
}

void PauseButton::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawPixmap(QRect(500,0,60,60),pix);
}

void PauseButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(isPause())
    {
        PauseState = 0;
        timer1->start();
        //timer2->start();
        timer3->start();
    }
    else
    {
        PauseState = 1;
        timer1->stop();
        //timer2->stop();
        timer3->stop();
    }
}

bool PauseButton::isPause()
{
    return PauseState;
}
