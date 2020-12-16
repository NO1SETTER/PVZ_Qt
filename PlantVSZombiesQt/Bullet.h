#pragma once
#include "Zombies.h"
#include "Common.h"
class bullet:public QGraphicsItem
{
protected:
    const int row;
	int x, y;//x,y�������ص��(��Ȼ��ôת�������������!! )
    int width,height;
	const int attack;
	const int speed;//�ӵ����ٶ��������ص�ǵ�,����Ҳ�������ص�ǵ�,���ʱֱ�Ӱ����ص������ʾ
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
    const int id;//��������ı��,���ڱ�ʶ
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

