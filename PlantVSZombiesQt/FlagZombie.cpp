#include"FlagZombie.h"
void FlagZombie::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    if(status == STAT_BOMB_DEAD)
    {
        if(deadCounter<15)
        {
            painter->drawPixmap(QRect(x-180,y-60,zombieBombWidth[zombieNameMap[name]],zombieBombHeight[zombieNameMap[name]]),bombGif->currentPixmap());
            deadCounter = deadCounter + 1;
        }
        else
        {
            scene()->removeItem(this);
            delete this;
        }
        return;
    }
    else if(status == STAT_HIT_DEAD)
    {
        if(deadCounter<15)
        {
            painter->drawPixmap(QRect(x-30,y+10,zombieHeadWidth[zombieNameMap[name]],zombieHeadHeight[zombieNameMap[name]]),headGif->currentPixmap());
            painter->drawPixmap(QRect(x-30,y+10,zombieBodyWidth[zombieNameMap[name]],zombieBodyHeight[zombieNameMap[name]]),deadBodyGif->currentPixmap());
            deadCounter = deadCounter + 1;
        }
        else
        {
            scene()->removeItem(this);
            delete this;
        }
        return;
    }
    else painter->drawPixmap(QRect(x,y,width,height),zombieGif->currentPixmap());
}
