#pragma once
#include "Bullet.h"
#include "Common.h"

class PumpkinHead;
class plant:public QGraphicsItem
{
protected:
	const int  x, y;
    int width,height;
	int health;
	const int interval;//作用间隔,如产生子弹,产生阳光
	int	counter;//对应interval的计数器
    QMovie* plantGif;
    PumpkinHead* ppk;//南瓜头指针
    //QPixmap* pix;
public:
	plant();
    plant(QString _name,int _x,int _y,int _health,int _cost,int _interval);
	~ plant();

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    int type()const override;
    void setGif(QString GifPath);

	void hurt(int damage);//hurt有可能更新地图
	virtual void dead();
	virtual void func(){}


    QString name;
	const int  id;
	const int  cost;

    bool addPumpkin(PumpkinHead* _ppk);
    PumpkinHead* getPumpkin();
	bool removePumpkin();
};

class SunFLower : public plant
{
public:
	void func();
    SunFLower(int _x, int _y) :
        plant("sunflower",_x, _y, 8, 50, 30)
	{
	}
};

class PeaShooter :public plant
{
public:
	void func();
    PeaShooter(int _x, int _y) :
        plant("peashooter", _x, _y,10,100,5)
	{
	}
};

class WallNut : public plant
{
public:
    WallNut(int _x, int _y) :
        plant("wallnut",_x, _y,80 ,50 ,0)
	{
	}
};

class SnowPea :public plant
{
public:
	void func();
    SnowPea(int _x, int _y) :
        plant("snowpea", _x, _y,10 ,175 ,5 )
	{
	}
};

class Repeater :public plant
{
public:
	void func();
    Repeater(int _x, int _y) :
        plant("repeater",_x ,_y,10 ,200 ,5)
	{
	}
};

class Squash : public plant
{
public:
	void func();
    Squash(int _x, int _y) :
        plant("squash", _x, _y, 100000, 50, 0)
	{
		attack = 80;
	}
private:
	int attack;
};

class TallNut: public plant
{
public:
    TallNut(int _x, int _y) :
        plant("tallnut", _x, _y, 200, 125, 0)
	{
	}
};

class CherryBomb : public plant
{
public:
	void func();
    CherryBomb(int _x, int _y):
        plant("cherrybomb", _x, _y, 10000, 150, 2)
	{
		attack = 80;
	}
private:
	int attack;
};


class Garlic: public plant
{
public:
    Garlic(int _x, int _y) :
        plant("garlic", _x, _y, 20, 50, 0)
	{
	}
};


class PumpkinHead :public plant
{
public:
    PumpkinHead(int _x, int _y) :
        plant("pumpkinhead", _x, _y, 60, 125, 0)
	{
	}
private:
	void dead();
};




