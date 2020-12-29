#include"BucketHeadZombie.h"


void BucketHeadZombie::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    if(!change_state&&health<=10)
    {
        name = "normalzombie";
        if(status!=STAT_BITE)
        {
            setGif("images/Zombies/NormalZombie/NormalZombie.gif");
            setRect(x,y+10,zombieWidth[0],zombieHeight[0]);
        }
        else
        {
            setGif("images/Zombies/NormalZombie/NormalZombieAttack.gif");
            setRect(x,y+10,zombieAttackWidth[zombieNameMap[name]],zombieAttackHeight[zombieNameMap[name]]);
        }
        change_state = 1;
    }
    if(status == STAT_BOMB_DEAD)
    {
        if(deadCounter<15)
        {
            painter->drawPixmap(QRect(x-200,y-80,zombieBombWidth[zombieNameMap[name]],zombieBombHeight[zombieNameMap[name]]),bombGif->currentPixmap());
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
            painter->drawPixmap(QRect(x-30,y-20,zombieHeadWidth[zombieNameMap[name]],zombieHeadHeight[zombieNameMap[name]]),headGif->currentPixmap());
            painter->drawPixmap(QRect(x-30,y-20,zombieBodyWidth[zombieNameMap[name]],zombieBodyHeight[zombieNameMap[name]]),deadBodyGif->currentPixmap());
            deadCounter = deadCounter + 1;
        }
        else
        {
            scene()->removeItem(this);
            delete this;
        }
        return;
    }
    painter->drawPixmap(QRect(x,y,width,height),zombieGif->currentPixmap());
}
