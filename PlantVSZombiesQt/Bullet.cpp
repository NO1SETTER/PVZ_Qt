#include "Bullet.h"
#include "Plants.h"
#include "Zombies.h"
bullet::bullet():
    name("Bullet"),row(0),attack(0),speed(0),id(rand()%10000)
{
	x = y = 0;
    width=height = 0;
    bulletGif = NULL;
}

bullet::bullet(QString _name,int _row,int _x,int _y,int _attack, int _speed):
    name(_name),row(_row),attack(_attack),speed(_speed),id(rand()%10000)
{
	x = _x;
	y = _y;
    width = bulletWidth[bulletNameMap[_name]];
    height = bulletHeight[bulletNameMap[_name]];
    bulletGif = NULL;
    QString bulletPath="images/Plants/"+_name+".gif";
    setGif(bulletPath);
}


QRectF bullet::boundingRect() const
{
    return QRectF(x,y,width,height);
}

void bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
Q_UNUSED(option);
Q_UNUSED(widget);
painter->drawPixmap(QRect(x,y,width,height),bulletGif->currentPixmap());
}

bool bullet::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
return 0;
}

int bullet::type()const
{
    return KIND_BULLET;
}

void bullet::setGif(QString bulletPath)
{
    if(bulletGif)
        delete bulletGif;
    bulletGif =new QMovie(bulletPath);
    bulletGif->start();
}

void bullet::advance(int phase)
{
    if(!phase) return;
    x = x + speed;
}
