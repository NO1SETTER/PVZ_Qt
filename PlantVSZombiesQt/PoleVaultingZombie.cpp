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

    if(jumpCounter >= 0)//��Ծ��ʱ������,��ô���������Ծ����
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
            speed = 1;//��Ծ���,�ָ�������״̬
            jumpCounter = -1;//��Ծ��ʱ���˺󲻻��ٱ�����
            QString zombiePath="images/Zombies/"+name+"/"+name+"walk.gif";
            setGif(zombiePath);
        }
        return;
    }
    QList<QGraphicsItem*> coItems=collidingItems();
    if(coItems.isEmpty()) //����Ծ״̬�ļ��
    {
       x = x - speed;
       if(status!=STAT_MOV) //û����ײ���ǲ���STAT_MOV״̬,��������ǰ������
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
        if(Pole)//����ײ�и�,������Ծ״̬,���ü�ʱ��jumpcounter������Ծ�����Ĳ���
        {
            jumpCounter = 0;//������ʱ������˼
            setGif("images/Zombies/PoleVaultingZombie/PoleVaultingZombieJump.gif");//��ǰ����һ�±������
            Pole = 0;
            if(frontplt->name=="tallnut") isTallNut=1;
            return;
        }
        if(status!=STAT_BITE&&!HasPole())//����ײ����û��,��ʼҧ
        {
            status=STAT_BITE;
            QString zombiePath="images/Zombies/"+name+"/"+name+"attack.gif";
            setGif(zombiePath);
        }
        bite(frontplt);
    }
}

void PoleVaultingZombie::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)//Ϊʲô��Ҫ����дһ��paint?��Ϊ��ʺ�زİ���sizeʵ����̫������
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
