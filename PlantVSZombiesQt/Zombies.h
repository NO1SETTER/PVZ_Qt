#pragma once
#include "Common.h"
#include "Plants.h"
class zombie :public QGraphicsItem
{
protected:

    int row;
    int x, y;
    int width,height;
	int health;
	int speed;//僵尸的速度是以像素点记的,坐标也是用像素点记的,但是输出时需要进行转化格子显示
	int attack;
	//也即[像素点区间]--->某一个y
	const int bonus;//击杀奖励
    QMovie* zombieGif;

    bool isVerticalWalking;
    int targetRow;
    int targetY;
    int verticalSpeed;//同时包含了方向
public:
    zombie();
    zombie(QString _name,int _row,int _x, int _y,int _health, int _attack, int _speed,int _bonus);

    QRectF boundingRect() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    int type()const override;
    void setGif(QString GifPath);
    void setRect(int _left,int _top,int _width,int _height);

    void advance(int phase) override;
	virtual void bite(plant* plt);//hurt有可能更新地图
	virtual void hurt(int damage);
	virtual void dead();
	void decelerate(int val, int mode);

    int getRow() {return row;}
    int getX() {return x;}
	const int id;//随机产生的编号,用于标识
	int status;//STAT_MOV,STAT_BITE
    QString name;

	friend class bullet;
	friend class PEA;
	friend class ICEPEA;
};

#define MODE_CHG 0
#define MODE_SET 1

