#include "Zombies.h"
#include "Plants.h"
#include<iostream>


plant::plant():
    name("plant"),row(0),col(0),x(0),y(0),cost(0),interval(0),id(rand()%10000)
{
	health = 0;
	counter = 0;
	ppk = NULL;
    plantGif = NULL;
}

plant::plant(QString _name,int _row,int _col,int _x,int _y,int _health,int _cost,int _interval):
    name(_name),row(_row),col(_col),x(_x),y(_y),cost(_cost),interval(_interval),id(rand()%10000)
{
    width = plantWidth[plantNameMap[_name]];
    height = plantHeight[plantNameMap[_name]];
    health = _health;
	counter = interval - 1;

	ppk = NULL;
    plantGif = NULL;
    QString plantPath="images/Plants/"+name+"/"+name+".gif";
    setGif(plantPath);
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

void PeaShooter::advance(int phase)
{
if(!phase) return;

int HasZombie=0;
QList<QGraphicsItem*> nowitems = scene()->items();
for(auto it=nowitems.begin();it!=nowitems.end();it++)
{
    if((*it)->type()==KIND_ZOMBIE)
    {
        //cout<<qgraphicsitem_cast<zombie*>(*it)->getRow()<<"   "<<row<<endl;
        if(qgraphicsitem_cast<zombie*>(*it)->getRow()==row)
        {HasZombie=1;
        break;
        }
    }
}
if(!HasZombie) return;

if(counter<interval)
{
    counter++;
    return;
}

counter = 0;
PeaBullet* newbul = new PeaBullet(row,x+width,y+height/6);
scene()->addItem(newbul);
}

void SnowPea::advance(int phase)
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

    if(counter<interval)
    {
        counter++;
        return;
    }

    counter = 0;
    SnowPeaBullet* newbul = new SnowPeaBullet(row,x+width,y+height/6);
    scene()->addItem(newbul);
}

void Repeater::advance(int phase)
{

}

