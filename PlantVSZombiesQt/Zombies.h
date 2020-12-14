#pragma once
#include "Common.h"

class zombie :public QGraphicsItem
{
protected:
    QString name;
    int x, y;
    int width,height;
	int health;
	int speed;//僵尸的速度是以像素点记的,坐标也是用像素点记的,但是输出时需要进行转化格子显示
	int attack;
	//也即[像素点区间]--->某一个y
	const int bonus;//击杀奖励
    QMovie* zombieGif;
public:
    zombie();
    zombie(int _x,int _y);
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

class ConeHeadZombie:public zombie
{
public:
    ConeHeadZombie(int _x,int _y):
        zombie("coneheadzombie",_x,_y-100,20,1,2,2)
    {

    }
};

class BucketHeadZombie:public zombie
{
public:
    BucketHeadZombie(int _x,int _y):
        zombie("bucketheadzombie",_x,_y-100,40,1,2,3)
    {

    }
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


#define MODE_CHG 0
#define MODE_SET 1
