#include"Sun.h"
Sun::Sun()//掉落的阳光
{
    x = rand()%600 + 100;
    y = 0;
    width = 80;
    height = 80;
    targetY = rand()%200+50;

    dead = 0;
    falling = 1;
    sunGif = new QMovie("images/Sun.gif");
    sunGif->start();

}

Sun::Sun(int _x,int _y)//植物产生的阳光
{
    x = _x;
    y = _y;
    width = 80;
    height = 80;

    falling = 0;
    dead = 0;
    sunGif = new QMovie("images/Sun.gif");
    sunGif->start();
}

QRectF Sun::boundingRect() const
{
    return QRectF(x,y,width,height);
}

void Sun::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    if(!dead)  painter->drawPixmap(QRect(x,y,width,height),sunGif->currentPixmap());//没办法只能这样实现了,就是很丑
}

void Sun::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    sun = sun + 25;
    sunGif->stop();
    scene()->removeItem(this);
    dead = 1;
}


void Sun::advance(int phase)
{
    if(!phase) return;
    if(!falling) return;
    if(y + 5 < targetY) y = y + 5;
    else
    {
        y = targetY;
        falling = 0;
    }
}
