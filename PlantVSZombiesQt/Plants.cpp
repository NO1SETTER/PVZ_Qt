#include "Zombies.h"
#include "Plants.h"
#include "PumpkinHead.h"


plant::plant():
    name("plant"),row(0),col(0),x(0),y(0),cost(0),id(rand()%10000)
{
	health = 0;
	ppk = NULL;
    plantGif = NULL;
}

plant::plant(QString _name,int _row,int _col,int _x,int _y,int _health,int _cost):
    name(_name),row(_row),col(_col),x(_x),y(_y),cost(_cost),id(rand()%10000)
{
    width = plantWidth[plantNameMap[_name]];
    height = plantHeight[plantNameMap[_name]];
    health = _health;

	ppk = NULL;
    plantGif = NULL;
    ppkBack = new QMovie("images/Plants/PumpkinHead/Pumpkin_Back.gif");
    ppk1 = new QMovie("images/Plants/PumpkinHead/PumpkinHead1.gif");
    ppk2 = new QMovie("images/Plants/PumpkinHead/Pumpkin_damage1.gif");
    ppk3 = new QMovie("images/Plants/PumpkinHead/Pumpkin_damage2.gif");
    ppkBack->start();
    ppk1->start();
    ppk2->start();
    ppk3->start();
    QString plantPath="images/Plants/"+name+"/"+name+".gif";
    setGif(plantPath);
}

bool plant::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode);
    return 0;
}

int plant::type()const
{
    return KIND_PLANT;
}

void plant::setGif(QString GifPath)
{
    if(plantGif)
        delete plantGif;
    plantGif = new QMovie(GifPath);
    plantGif->start();
}


void plant::hurt(int damage)
{
	health = health - damage;
    if(health<=0) dead();
}

void plant::dead()
{
    scene()->removeItem(this);
    delete this;
}

void plant::setRect(int _left,int _top,int _width,int _height)
{
    x = _left;
    y = _top;
    width = _width;
    height = _height;
}

QRectF plant::boundingRect() const
{
    return QRectF(x,y,width,height);
}

void plant::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    if(ppk)
    {
        painter->drawPixmap(QRect(x-5,y+35,plantWidth[9],plantHeight[9]),ppkBack->currentPixmap());
        painter->drawPixmap(QRect(x,y,width,height),plantGif->currentPixmap());
        if(ppk->health>150)
             painter->drawPixmap(QRect(x-5,y+30,plantWidth[9],plantHeight[9]),ppk1->currentPixmap());
        else if(ppk->health>80)  painter->drawPixmap(QRect(x-5,y+30,plantWidth[9],plantHeight[9]),ppk2->currentPixmap());
        else  painter->drawPixmap(QRect(x-5,y+30,plantWidth[9],plantHeight[9]),ppk3->currentPixmap());
    }
    else painter->drawPixmap(QRect(x,y,width,height),plantGif->currentPixmap());
}

bool plant::addPumpkin(PumpkinHead* _ppk)//给它传一个空的也ok
{
	if (ppk) return 0;
	ppk = _ppk;
	return 1;
}

PumpkinHead* plant::getPumpkin()
{
	return ppk;
}

bool plant::removePumpkin()
{
	if (!ppk) return 0;
	ppk = NULL;
	return 1;
}










