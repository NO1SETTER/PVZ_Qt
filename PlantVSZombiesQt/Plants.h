#pragma once
#include "Bullet.h"
#include "Common.h"

class PumpkinHead;
class plant:public QGraphicsItem
{
protected:
    const int row,col;
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
    plant(QString _name,int _row,int _col,int _x,int _y,int _health,int _cost,int _interval);
	~ plant();

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    int type()const override;
    void setGif(QString GifPath);

	void hurt(int damage);//hurt有可能更新地图
	virtual void dead();

    QString name;
	const int  id;
	const int  cost;

    bool addPumpkin(PumpkinHead* _ppk);
    PumpkinHead* getPumpkin();
	bool removePumpkin();
    int getRow() {return row;}
    int getCol() {return col;}
    QString getName() {return name;}
};

class SunFLower : public plant
{
public:
    SunFLower(int _row,int _col,int _x, int _y) :
        plant("sunflower",_row,_col,_x, _y, 8, 50, 30)
	{
	}
};

class PeaShooter :public plant
{
public:
    void advance(int phase)override;
    PeaShooter(int _row,int _col,int _x, int _y) :
        plant("peashooter",_row,_col, _x, _y,10,100,20)
	{
	}
};

class WallNut : public plant
{
public:
    WallNut(int _row,int _col,int _x, int _y) :
        plant("wallnut",_row,_col,_x, _y,80 ,50 ,0)
	{
	}
};

class SnowPea :public plant
{
public:
    void advance(int phase)override;
    SnowPea(int _row,int _col,int _x, int _y) :
        plant("snowpea",_row,_col, _x, _y,10 ,175 ,20)
	{
	}
};

class Repeater :public plant
{
public:
    void advance(int phase)override;
    Repeater(int _row,int _col,int _x, int _y) :
        plant("repeater",_row,_col, _x ,_y,10 ,200 ,20)
	{
	}
};

class Squash : public plant
{
public:
    Squash(int _row,int _col,int _x, int _y) :
        plant("squash",_row,_col, _x, _y, 100000, 50, 0)
	{
		attack = 80;
	}
private:
	int attack;
};

class TallNut: public plant
{
public:
    TallNut(int _row,int _col,int _x, int _y) :
        plant("tallnut",_row,_col, _x, _y, 200, 125, 0)
	{
	}
};

class CherryBomb : public plant
{
public:
    CherryBomb(int _row,int _col,int _x, int _y):
        plant("cherrybomb",_row,_col, _x, _y, 10000, 150, 2)
	{
		attack = 80;
	}
private:
	int attack;
};


class Garlic: public plant
{
public:
    Garlic(int _row,int _col,int _x, int _y) :
        plant("garlic",_row,_col, _x, _y, 20, 50, 0)
	{
	}
};


class PumpkinHead :public plant
{
public:
    PumpkinHead(int _row,int _col,int _x, int _y) :
        plant("pumpkinhead",_row,_col, _x, _y, 60, 125, 0)
	{
	}
};




