#include "Grassland.h"
#include "Shovel.h"
#include<iostream>

Grassland::Grassland()
{
    x = y = 0;
    dragOver = 0;
    setAcceptDrops(1);
}

Grassland::Grassland(int _x, int _y)
{
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
    else
        event->setAccepted(0);
}

void Grassland::dragLeaveEvent(QGraphicsSceneDragDropEvent *event)
{
    Q_UNUSED(event);
    update();
}

void Grassland::dropEvent(QGraphicsSceneDragDropEvent *event)
{
    QPointF pos = event->pos();
    //std::cout<<pos.x()<<" "<<pos.y()<<std::endl;
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
            switch (plantType)
            {
                case 0:
                    newplant = new SunFLower(x,y); break;
                case 1:
                    newplant = new PeaShooter(x,y); break;
                case 2:
                    newplant = new WallNut(x,y); break;
                case 3:
                    newplant = new SnowPea(x,y); break;
                case 4:
                    newplant = new Repeater(x,y); break;
                case 5:
                    newplant = new Squash(x,y); break;
                case 6:
                    newplant = new TallNut(x,y); break;
                case 7:
                    newplant = new CherryBomb(x,y); break;
                case 8:
                    newplant = new Garlic(x,y); break;
                case 9:
                    newplant = new PumpkinHead(x,y); break;
                default:
                    assert(0);
            }
            scene()->addItem(newplant);
        }
    }
}

int Grassland::type()const
{
    return KIND_GRASS;
}



