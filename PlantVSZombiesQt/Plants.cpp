#include "Zombies.h"
#include "Plants.h"
#include<iostream>


plant::plant():
    name("plant"),x(0),y(0),cost(0),interval(0),id(rand()%10000)
{
	health = 0;
	counter = 0;
	ppk = NULL;
    plantGif = NULL;
}

plant::plant(QString _name,int _x,int _y,int _health,int _cost,int _interval):
    name(_name),x(_x),y(_y),cost(_cost),interval(_interval),id(rand()%10000)
{
    width = plantWidth[plantNameMap[_name]];
    height = plantHeight[plantNameMap[_name]];
    health = _health;
	counter = interval - 1;

	ppk = NULL;
    plantGif = NULL;
    QString tempPath="images/Plants/"+name+"/"+name+".gif";
    setGif(tempPath);

    //QRectF rect = this->boundingRect();
}

bool plant::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode);
    QRectF rect1 = this->boundingRect();
    QRectF rect2 = other->boundingRect();
    return (other->type() == KIND_ZOMBIE) && (rect1.top() == rect2.top()) && (rect1.left() + rect1.width() + 30 >= rect2.left());
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

plant::~plant()
{
}

void plant::hurt(int damage)
{
	health = health - damage;
	if (health <= 0)
		dead();
}

void plant::dead()
{
}


QRectF plant::boundingRect() const
{
    return QRectF(x,y,width,height);
}

void plant::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    if(name == "pumpkinhead")
        painter->drawPixmap(QRect(x,y+20,width,height),plantGif->currentPixmap());
    else
        painter->drawPixmap(QRect(x,y,width,height),plantGif->currentPixmap());
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

void SunFLower::func()
{
	if (counter < interval)
	{
		counter += 1;
		return;
	}
	counter = 0;
	sun = sun + 50;
}

void PeaShooter::func()
{

}


void SnowPea::func()
{

}

void Repeater::func()
{
}

void Squash::func()
{

}

void CherryBomb::func()
{

}

void PumpkinHead::dead()
{

}

