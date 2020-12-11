#pragma once
#include "Common.h"

class zombie :public QGraphicsItem
{
protected:
    QString name;
    int x, y;
	int health;
	int speed;//僵尸的速度是以像素点记的,坐标也是用像素点记的,但是输出时需要进行转化格子显示
	int attack;
	//也即[像素点区间]--->某一个y
	const int bonus;//击杀奖励
    QMovie* zombieGif;
public:
	zombie();
    zombie(QString _name, int _x, int _y,int _health, int _attack, int _speed,int _bonus);
	~zombie();

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    int type()const override;
    void setGif(QString GifPath);

	virtual void bite(plant* plt);//hurt有可能更新地图
	virtual void hurt(int damage);
	virtual void move();
	virtual bool func() {
		return 0;
	}//返回func是否发动了技能
	virtual void dead();
	void decelerate(int val, int mode);
	void accelerate(int val, int mode);


	const int id;//随机产生的编号,用于标识
	int status;//STAT_MOV,STAT_BITE
	

	friend class bullet;
	friend class PEA;
	friend class ICEPEA;
};

class NormalZombie:public zombie
{
public:
    NormalZombie(int _x,int _y):
        zombie("normalzombie",_x,_y,10,1,2,1)
    {

    }
};

class ConeHeadZombie:public zombie
{
public:
    ConeHeadZombie(int _x,int _y):
        zombie("coneheadzombie",_x,_y,20,1,2,2)
    {

    }
};

class BucketHeadZombie:public zombie
{
public:
    BucketHeadZombie(int _x,int _y):
        zombie("bucketheadzombie",_x,_y,40,1,2,3)
    {

    }
};

class NewspaperZombie:public zombie
{
public:
	bool func();
    NewspaperZombie(int _x, int _y) :
        zombie("newspaperzombie",_x,_y,40,1,2,3)
	{
		activated = 0;
	}
private:
	int activated;
};

class PoleVaultingZombie :public zombie
{
public:
	bool func();
    PoleVaultingZombie(int _x, int _y) :
        zombie("polevaultingzombie", _x, _y,15,1,3,2)
	{
		activated = 0;
	}
private:
	int activated;
};

class  ClownZombie:public zombie
{
public:
    ClownZombie(int _x, int _y) :
        zombie("clownzombie", _x, _y,20,1,2,3)
	{
	}
	bool func();
	void dead();
};


class CatapultZombie:public zombie
{
public:
    CatapultZombie(int _x, int _y) :
        zombie("catapultzombie", _x, _y,30,1000,1,3)
	{
		status = STAT_WAIT;//投篮僵尸初始状态是wait
		ballNum = 10;
		counter = 6;
		tarX = _x;
		tarY = 0;//默认投掷目标
	}
	bool func();
private:
	int ballNum;
	int counter;
	int tarX, tarY;
};

class Basketball :public zombie//把投篮僵尸产生的篮球视作也是一种僵尸
{
public:
    Basketball(int _x, int _y) :
        zombie("basketball", _x, _y, 10000, 3, 4, 0)
	{
	}
	bool func();
private:
	int tarX,tarY;//锁定目标
};

#define MODE_CHG 0
#define MODE_SET 1
