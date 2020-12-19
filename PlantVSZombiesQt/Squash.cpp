#include"Squash.h"



bool Squash::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode);
    if(other->type()!=KIND_ZOMBIE) return 0;
    zombie* frontzb = qgraphicsitem_cast<zombie*>((QGraphicsItem*)other);
    if(frontzb->getRow()==row && frontzb->getX()>=grassX[col]-40&&frontzb->getX()<=grassX[col+1]+30) return 1;
    return 0;
}

void Squash::advance(int phase)
{
    if(!phase) return;
    QList<QGraphicsItem*> coItems=collidingItems();
    if(!coItems.isEmpty()&&attackCounter == -1)
    {
        attackCounter = 0;
        for(auto it=coItems.begin();it!=coItems.end();it++)
            WipeOutList.append(*it);
        setRect(x,y-50,110,160);
    }
    if(attackCounter >= 0)
    {
        if(status==STAT1)
        {
            status=STAT2;
            setGif("images/Plants/Squash/SquashAttack.gif");
        }//设置开始进攻动作
        else if(status==STAT2&&attackCounter< 8)
        {
            attackCounter = attackCounter + 1;
        }//进攻动作播放中
        else
        {
            for(auto it=WipeOutList.begin();it!=WipeOutList.end();it++)
                qgraphicsitem_cast<zombie*>(*it)->hurt(80);
            this->dead();
        }//完成进攻动作,植物消失
    }

}
