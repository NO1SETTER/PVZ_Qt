#include "Grassland.h"
#include "Shovel.h"
#include "SunFLower.h"
#include "PeaShooter.h"
#include "SnowPea.h"
#include "Repeater.h"
#include "WallNut.h"
#include "Squash.h"
#include "TallNut.h"
#include "CherryBomb.h"
#include "Garlic.h"
#include "PumpkinHead.h"
#include "Cards.h"

Grassland::Grassland()
{
    x = y = 0;
    row = col = 0;
    dragOver = 0;
    setAcceptDrops(1);
}

Grassland::Grassland(int _x, int _y)
{
    row = _y;
    col = _x;
    x = grassX[_x];
    y = grassY[_y];
    width = grassX[_x + 1] - grassX[_x];
    height = grassY[_y + 1] - grassY[_y];
    dragOver = 0;
    setAcceptDrops(1);
}

void Grassland::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(painter);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF Grassland::boundingRect() const
{
    return QRect(x,y,80,100); //设置触发的区域
}

void Grassland::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{
    if(event->mimeData()->hasText())
    {
        event->setAccepted(1);
        update();
    }
    else event->setAccepted(0);
}

void Grassland::dragLeaveEvent(QGraphicsSceneDragDropEvent *event)
{
    Q_UNUSED(event);
    update();
}

void Grassland::dropEvent(QGraphicsSceneDragDropEvent *event)
{
    QPointF pos = event->pos();
    if(event->mimeData()->hasText())
    {
        QString data=event->mimeData()->text();
        if(data=="shovel")
        {
            QList<QGraphicsItem*> nowitems = scene()->items();
             for(auto it=nowitems.begin();it!=nowitems.end();it++)
             {
                 if((*it)->type()==KIND_PLANT)
                 {
                     qgraphicsitem_cast<Shovel* >(*it)->remove(event->pos());
                     break;
                 }
             }

        }
        else
        {
            int plantType = -1;
            for(int i=0;i<10;i++)
                if(data == plantName[i])
                {
                    plantType=i;
                    break;
                }
            plant* newplant = NULL;
            plant* existplant=NULL;
            int plantNum = 0;
            QList<QGraphicsItem*> allplants=scene()->items();
            for(auto it=allplants.begin();it!=allplants.end();it++)
            {
                if((*it)->type()!=KIND_PLANT) continue;
                if(qgraphicsitem_cast<plant*>(*it)->getRow()==row&&qgraphicsitem_cast<plant*>(*it)->getCol()==col)
                {
                    existplant=qgraphicsitem_cast<plant*>(*it);
                    plantNum = plantNum + 1;
                }
            }
            if(plantNum >= 2) return;
            if(plantNum == 1)
            {
                if(existplant->getName() == "pumpkinhead" && plantName[plantType]=="pumpkinhead") return;
                if(existplant->getName() != "pumpkinhead" && plantName[plantType]!="pumpkinhead") return;
            }
            switch (plantType)
            {
                case 0:
                    newplant = new SunFLower(row,col,x,y); break;
                case 1:
                    newplant = new PeaShooter(row,col,x,y); break;
                case 2:
                    newplant = new WallNut(row,col,x,y); break;
                case 3:
                    newplant = new SnowPea(row,col,x,y); break;
                case 4:
                    newplant = new Repeater(row,col,x,y); break;
                case 5:
                    newplant = new Squash(row,col,x,y); break;
                case 6:
                    newplant = new TallNut(row,col,x+5,y-10); break;
                case 7:
                    newplant = new CherryBomb(row,col,x,y+10); break;
                case 8:
                    newplant = new Garlic(row,col,x+5,y+10); break;
                case 9:
                    newplant = new PumpkinHead(row,col,x,y+20); break;
                default:
                    assert(0);
            }
            if(sun < newplant->cost || !cards[plantType]->available()) return;
            else {
                sun =sun - newplant->cost;
                cards[plantType]->resetCD();
            }

            if(plantNum==1)//说明一定是叠南瓜的情况
            {
                if(newplant->getName()=="pumpkinhead")
                {
                    existplant->addPumpkin(qgraphicsitem_cast<PumpkinHead*>(newplant));
                    qgraphicsitem_cast<PumpkinHead*>(newplant)->setProtector(existplant);

                }
                else
                {
                    newplant->addPumpkin(qgraphicsitem_cast<PumpkinHead*>(existplant));
                    qgraphicsitem_cast<PumpkinHead*>(existplant)->setProtector(newplant);
                }
            }
            scene()->addItem(newplant);

        }
    }
}

int Grassland::type()const
{
    return KIND_GRASS;
}



