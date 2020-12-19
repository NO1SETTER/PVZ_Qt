#include"Repeater.h"
#include"PeaBullet.h"


void Repeater::advance(int phase)
{
    if(!phase) return;
    int HasZombie=0;
    QList<QGraphicsItem*> nowitems = scene()->items();
    for(auto it=nowitems.begin();it!=nowitems.end();it++)
    {
        if((*it)->type()==KIND_ZOMBIE)
        {
            if(qgraphicsitem_cast<zombie*>(*it)->getRow()==row)
            {HasZombie=1;
            break;}
        }
    }
    if(!HasZombie) return;

    if(counter<20)
    {
        counter++;
        return;
    }

    counter = 0;
    PeaBullet* newbul1 = new PeaBullet(row,x+width,y+height/6);
    PeaBullet* newbul2 = new PeaBullet(row,x+width+20,y+height/6);
    scene()->addItem(newbul1);
    scene()->addItem(newbul2);

}
