#pragma once
#include "Common.h"

class zombie :public QGraphicsItem
{
protected:
    QString name;
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
    zombie(int _x,int _y);
    zombie(QString _name, int _x, int _y,int _health, int _attack, int _speed,int _bonus);
	~zombie();

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    int type()const override;
    void setGif(QString GifPath);

	virtual void bite(plant* plt);//hurt�п��ܸ��µ�ͼ
	virtual void hurt(int damage);
	virtual void move();
	virtual bool func() {
		return 0;
	}//����func�Ƿ񷢶��˼���
	virtual void dead();
	void decelerate(int val, int mode);
	void accelerate(int val, int mode);

	const int id;//��������ı��,���ڱ�ʶ
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
