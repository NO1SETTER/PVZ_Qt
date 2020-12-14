#include "Zombies.h"
#include "Plants.h"
/*
extern QString zombiePath[5]={
    "images/Zombies/Zombie/Zombie.gif",
    "images/Zombies/ConeHeadZombie/ConeHeadZombie.gif",
    "images/Zombies/BucketHeadZombie/BucketHeadZombie.gif",
    "images/Zombies/FlagZombie/FlagZombie.gif",
    "images/Zombies/PoleVaultingZombie/PoleVaultingZombie.gif"
};
*/
zombie::zombie():
	name("Zombie"),attack(0),bonus(0),id(rand()%10000)
{
	x = 0;
	y = 0;
	health = 0;
	speed = 0;
    zombieGif = NULL;
	status = STAT_MOV;
}

zombie::zombie(int _x,int _y):           //这个其实不是zombie基类的构造器,它其实是代表原本应有的派生类普通僵尸的构造器
    name("zombie"),x(_x),y(_y-10),health(10),attack(1),speed(2),bonus(1),id(rand()%10000)
{
    width=zombieWidth[zombieNameMap["zombie"]];
    height=zombieHeight[zombieNameMap["zombie"]];
    status=STAT_MOV;
    zombieGif = NULL;
    QString zombiePath="images/Zombies/Zombie/Zombie.gif";
    setGif(zombiePath);
}


zombie:: zombie(QString _name, int _x, int _y,int _health, int _attack, int _speed,int _bonus):
    name(_name),x(_x),y(_y),attack(_attack),bonus(_bonus),id(rand()%10000)
{
    width=zombieWidth[zombieNameMap[_name]];
    height=zombieHeight[zombieNameMap[_name]];
	health = _health;
	speed = _speed;
	status = STAT_MOV;
    zombieGif = NULL;
    QString zombiePath="images/Zombies/"+_name+"/"+_name+".gif";
    setGif(zombiePath);
}

zombie::~zombie()
{
}

QRectF zombie::boundingRect() const
{
    return QRectF(x,y,width,height);
}

void zombie::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawPixmap(QRect(x,y,width,height),zombieGif->currentPixmap());
}

bool zombie::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    return 0;
}

int zombie::type()const
{
    return KIND_ZOMBIE;
}

void zombie::setGif(QString GifPath)
{
    if(zombieGif)
        delete zombieGif;
    zombieGif = new QMovie(GifPath);

    zombieGif->start();
}

void zombie::bite(plant* plt)
{
}

void zombie::move()
{

}

void zombie::hurt(int damage)
{
	health = health - damage;
	if (health <= 0)
		dead();
}

void zombie::dead()
{
	point = point + bonus;
}

void zombie::accelerate(int val, int mode)
{
	if (mode == MODE_CHG)
		speed = speed + val;
	else
		speed = val;
}

void zombie::decelerate(int val, int mode)
{
	if (mode == MODE_CHG)
		speed = max(1, speed - val);
	else
		speed = val;
}


bool PoleVaultingZombie:: func()
{
    return 0;
}





