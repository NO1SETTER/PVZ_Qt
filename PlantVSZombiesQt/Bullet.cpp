#include "Bullet.h"
#include "Plants.h"
#include "Zombies.h"
#include "PoleVaultingZombie.h"

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
    Q_UNUSED(mode);
    if(other->type()!=KIND_ZOMBIE) return 0;//只与僵尸产生碰撞
    zombie* frontzb=qgraphicsitem_cast<zombie*>((QGraphicsItem*)other);
    int zrow = frontzb->getRow();
    QRectF rect1=this->boundingRect();
    QRectF rect2=other->boundingRect();

    if(frontzb->status == STAT_HIT_DEAD || frontzb->status == STAT_BOMB_DEAD) return 0;//已经死亡但是仍然在播放动画的僵尸

    if(frontzb->name=="polevaultingzombie"&&qgraphicsitem_cast<PoleVaultingZombie*>(frontzb)->HasPole())
    {
         if(row == zrow &&rect1.left()+rect1.width()-110>=rect2.left() && rect1.left()-100<= rect2.left()) return 1;
    }
    else if(frontzb->name=="polevaultingzombie")
    {
        if(row == zrow && rect1.left()+rect1.width()-150>=rect2.left() && rect1.left()-140<=rect2.left()) return 1;
    }
    else if(row == zrow &&rect1.left()+rect1.width()-30>=rect2.left() && rect1.left()-20<= rect2.left()) return 1;

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
    QList<QGraphicsItem*> coItems=collidingItems();
    if(coItems.isEmpty())
    {
         x = x + speed;
    }
    else
    {
        zombie* frontzb=qgraphicsitem_cast<zombie*>(coItems[0]);
        frontzb->hurt(attack);
        scene()->removeItem(this);
        delete this;
        return;
    }
}
