#include"SnowPeaBullet.h"

void SnowPeaBullet::advance(int phase)
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
        frontzb->decelerate(1,MODE_CHG);
        scene()->removeItem(this);
        delete this;
        return;
    }
}
