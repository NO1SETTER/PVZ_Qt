#pragma once
#include "Common.h"

class zombie :public QGraphicsItem
{
protected:
    QString name;
    int x, y;
	int health;
	int speed;//��ʬ���ٶ��������ص�ǵ�,����Ҳ�������ص�ǵ�,�������ʱ��Ҫ����ת��������ʾ
	int attack;
	//Ҳ��[���ص�����]--->ĳһ��y
	const int bonus;//��ɱ����
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
		status = STAT_WAIT;//Ͷ����ʬ��ʼ״̬��wait
		ballNum = 10;
		counter = 6;
		tarX = _x;
		tarY = 0;//Ĭ��Ͷ��Ŀ��
	}
	bool func();
private:
	int ballNum;
	int counter;
	int tarX, tarY;
};

class Basketball :public zombie//��Ͷ����ʬ��������������Ҳ��һ�ֽ�ʬ
{
public:
    Basketball(int _x, int _y) :
        zombie("basketball", _x, _y, 10000, 3, 4, 0)
	{
	}
	bool func();
private:
	int tarX,tarY;//����Ŀ��
};

#define MODE_CHG 0
#define MODE_SET 1
