#include"CherryBomb.h"



bool CherryBomb::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
if(other->type()!=KIND_ZOMBIE) return 0;
zombie* frontzb=qgraphicsitem_cast<zombie*>((zombie*)other);
if(!((frontzb->getRow()==row)||frontzb->getRow()==row-1||frontzb->getRow()==row+1)) return 0;
if(frontzb->getX()<=grassX[col]+140&&frontzb->getX()>=grassX[col]-130) return 1;
return 0;
}

void CherryBomb::advance(int phase)
{
    if(!phase) return;
    QList<QGraphicsItem*> coItems=collidingItems();
    if(bombCounter==-1)
    {
        bombCounter = 0;
        for(auto it=coItems.begin();it!=coItems.end();it++)
            WipeOutList.append(*it);
    }

    if(bombCounter>=0)
    {
        if(bombCounter<=5)
            bombCounter = bombCounter + 1;
        else
        {
            if(status!=STAT2&&bombCounter<10)
            {
                status = STAT2;
                setGif("images/Plants/CherryBomb/Boom.gif");
                setRect(x-80,y-50,250,200);
            }
            else if(bombCounter<10)
                bombCounter = bombCounter + 1;
            else
            {
                for(auto it=WipeOutList.begin();it!=WipeOutList.end();it++)
                    qgraphicsitem_cast<zombie*>(*it)->hurt(80);
                this->dead();
            }
        }
    }
}
