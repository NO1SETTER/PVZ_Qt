#pragma once
#include "Zombies.h"
#include "Common.h"
class bullet:public QGraphicsItem
{
protected:
    const int row;
	int x, y;//x,y均以像素点计(不然怎么转化成坐标输出啊!! )
    int width,height;
	const int attack;
	const int speed;//子弹的速度是以像素点记的,坐标也是以像素点记的,输出时直接按像素点进行显示
    QMovie* bulletGif;
public:
	bullet();
    bullet(QString _name,int _row,int _x,int _y,int _attack, int _speed);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    int type()const override;
    void setGif(QString bulletPath);
    void advance(int phase)override;

    int getRow() {return row;}

    QString name;
    const int id;//随机产生的编号,用于标识
};

class PeaBullet :public bullet
{
public:
    PeaBullet(int _row, int _x, int _y) :
        bullet("peabullet",_row,_x,_y,1,5)
	{
	}
};

class SnowPeaBullet :public bullet
{
public:
    SnowPeaBullet(int _row, int _x, int _y) :
        bullet("snowpeabullet",_row,_x,_y,1,5)
	{
	}
};

