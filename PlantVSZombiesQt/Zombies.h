#pragma once
#include "Common.h"

class zombie :public QGraphicsItem
{
protected:
    QString name;
    int row;
    int x, y;
    int width,height;
	int health;
	int speed;//��ʬ���ٶ��������ص�ǵ�,����Ҳ�������ص�ǵ�,�������ʱ��Ҫ����ת��������ʾ
	int attack;
	//Ҳ��[���ص�����]--->ĳһ��y
	const int bonus;//��ɱ����
    QMovie* zombieGif;
public:
    zombie();
    zombie(QString _name,int _row,int _x, int _y,int _health, int _attack, int _speed,int _bonus);
	~zombie();

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    int type()const override;
    void setGif(QString GifPath);

    void advance(int phase) override;
	virtual void bite(plant* plt);//hurt�п��ܸ��µ�ͼ
	virtual void hurt(int damage);
	virtual void move();
	virtual bool func() {
		return 0;
	}//����func�Ƿ񷢶��˼���
	virtual void dead();
	void decelerate(int val, int mode);
	void accelerate(int val, int mode);
    int getRow() {return row;}

	const int id;//��������ı��,���ڱ�ʶ
	int status;//STAT_MOV,STAT_BITE
	
	friend class bullet;
	friend class PEA;
	friend class ICEPEA;
};


class NormalZombie:public zombie
{
public:
    NormalZombie(int _row,int _x,int _y):
        zombie("normalzombie",_row,_x,_y-10,10,1,1,1)
    {

    }

};

class ConeHeadZombie:public zombie
{
public:
    ConeHeadZombie(int _row,int _x,int _y):
        zombie("coneheadzombie",_row,_x,_y-30,20,1,1,2)
    {

    }
};

class BucketHeadZombie:public zombie
{
public:
    BucketHeadZombie(int _row,int _x,int _y):
        zombie("bucketheadzombie",_row,_x,_y-30,40,1,1,3)
    {

    }
};

class FlagZombie:public zombie
{
public:
    FlagZombie(int _row,int _x,int _y):
        zombie("flagzombie",_row,_x,_y-40,10,1,1,1)
    {
    }
};

class PoleVaultingZombie :public zombie
{
public:
    PoleVaultingZombie(int _row,int _x, int _y) :
        zombie("polevaultingzombie",_row, _x, _y-120,15,1,3,2)
    {
	}
    //void advance(int phase) override;
};




#define MODE_CHG 0
#define MODE_SET 1
