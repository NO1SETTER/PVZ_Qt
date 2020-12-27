#include"PoleVaultingZombie.h"

bool PoleVaultingZombie::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    if(other->type()!=KIND_PLANT&&other->type()!=KIND_BULLET) return 0;
    if(other->type() == KIND_PLANT)
    {
        plant* frontplt =  qgraphicsitem_cast<plant*>((QGraphicsItem*)other);
        int prow =frontplt->getRow();
        int col = frontplt->getCol();
        if(row == prow &&(this->x>=grassX[col]-100 ) && this->x<=grassX[col]-20) return 1;
    }
    return 0;
}

void PoleVaultingZombie::advance(int phase)
{
    if(!phase) return;
    if(isVerticalWalking)
    {
       if(verticalSpeed > 0)
       {
           if(y + verticalSpeed < targetY) y = y + verticalSpeed;
           else
           {
               y = targetY;
               row = targetRow;
               isVerticalWalking = 0;
           }
       }
       else
       {
           if(y + verticalSpeed > targetY) y = y + verticalSpeed;
           else
           {
               y = targetY;
               row = targetRow;
               isVerticalWalking = 0;
           }
       }
    }

    if(jumpCounter >= 0)//跳跃计时器启动,那么优先完成跳跃过程
    {
        if(jumpCounter<jumpTime1)
        {
            if(status!=STAT_JUMP1)
            {
                QString jumpPath1="images/Zombies/PoleVaultingZombie/PoleVaultingZombieJump.gif";
                setGif(jumpPath1);
                status=STAT_JUMP1;
                if(isTallNut) speed = 0;
                else speed = 9;

            }
            else
            {
                jumpCounter = jumpCounter + 1;
                x = x - speed;
            }
        }
        else if(jumpCounter<jumpTime2)
        {
            if(status!=STAT_JUMP2)
            {
                status=STAT_JUMP2;
                QString jumpPath2="images/Zombies/PoleVaultingZombie/PoleVaultingZombieJump2.gif";
                setGif(jumpPath2);
            }
            else
            {
                jumpCounter = jumpCounter + 1;
                x = x - speed;
            }
        }
        else
        {
            speed = 1;//跳跃完成,恢复成行走状态
            jumpCounter = -1;//跳跃计时器此后不会再被启动
            QString zombiePath="images/Zombies/"+name+"/"+name+"walk.gif";
            setGif(zombiePath);
        }
        return;
    }
    QList<QGraphicsItem*> coItems=collidingItems();
    if(coItems.isEmpty()) //非跳跃状态的检查
    {
       x = x - speed;
       if(status!=STAT_MOV) //没有碰撞但是不是STAT_MOV状态,可能是跳前或跳后
       {
           status=STAT_MOV;
           QString zombiePath;
           if(HasPole())
             zombiePath="images/Zombies/"+name+"/"+name+".gif";
           else
             zombiePath="images/Zombies/"+name+"/"+name+"walk.gif";
           setGif(zombiePath);
       }
    }
    else
    {
        plant* frontplt=qgraphicsitem_cast<plant*>(coItems[0]);
        if(Pole)//有碰撞有杆,启动跳跃状态,利用计时器jumpcounter控制跳跃动作的播放
        {
            jumpCounter = 0;//启动计时器的意思
            setGif("images/Zombies/PoleVaultingZombie/PoleVaultingZombieJump.gif");//提前设置一下避免变形
            Pole = 0;
            if(frontplt->name=="tallnut") isTallNut=1;
            return;
        }
        if(status!=STAT_BITE&&!HasPole())//有碰撞但是没杆,开始咬
        {
            status=STAT_BITE;
            QString zombiePath="images/Zombies/"+name+"/"+name+"attack.gif";
            setGif(zombiePath);
        }
        bite(frontplt);
    }
}

void PoleVaultingZombie::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)//为什么它要重新写一个paint?因为狗屎素材包的size实在是太垃圾了
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    if(status == STAT_MOV && Pole) painter->drawPixmap(QRect(x-40,y+15,zombieWidth[4],zombieWidth[4]),zombieGif->currentPixmap());
    else if(status == STAT_MOV) painter->drawPixmap(QRect(x-80,y+15,PVZ_WALKING_WIDTH,PVZ_WALKING_HEIGHT),zombieGif->currentPixmap());
    else if(status == STAT_JUMP1) painter->drawPixmap(QRect(x-60,y+15,PVZ_JUMP1_WIDTH,PVZ_JUMP1_HEIGHT),zombieGif->currentPixmap());
    else if(status == STAT_JUMP2) painter->drawPixmap(QRect(x-60,y+15,PVZ_JUMP2_WIDTH,PVZ_JUMP2_HEIGHT),zombieGif->currentPixmap());
    else if(status == STAT_BITE)
    painter->drawPixmap(QRect(x-80,y+15,zombieAttackWidth[4],zombieAttackHeight[4]),zombieGif->currentPixmap());
}

int PoleVaultingZombie::jumpTime1 = 5;
int PoleVaultingZombie::jumpTime2 = 10;
