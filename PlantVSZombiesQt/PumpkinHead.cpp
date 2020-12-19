#include"PumpkinHead.h"



void PumpkinHead::dead()
{
    if(protector) protector->removePumpkin();
    scene()->removeItem(this);
    delete this;
}

 void PumpkinHead::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
 {
    Q_UNUSED(option);
    Q_UNUSED(widget);
     if(protector) return;
     else painter->drawPixmap(QRect(x,y+20,width,height),plantGif->currentPixmap());
 }


 void PumpkinHead::setProtector(plant* plt)
 {
     protector = plt;}
 void PumpkinHead::removeProtector()
 {
     protector = NULL;}
