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
	int speed;//��ʬ���ٶ��������ص�ǵ�,����Ҳ�������ص�ǵ�,�������ʱ��Ҫ����ת��������ʾ
	int attack;
	//Ҳ��[���ص�����]--->ĳһ��y
	const int bonus;//��ɱ����
    QMovie* zombieGif;

    bool isVerticalWalking;
    int targetRow;
    int targetY;
    int verticalSpeed;//ͬʱ�����˷���
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
	virtual void bite(plant* plt);//hurt�п��ܸ��µ�ͼ
	virtual void hurt(int damage);
	virtual void dead();
	void decelerate(int val, int mode);

    int getRow() {return row;}
    int getX() {return x;}
	const int id;//��������ı��,���ڱ�ʶ
	int status;//STAT_MOV,STAT_BITE
    QString name;

	friend class bullet;
	friend class PEA;
	friend class ICEPEA;
};

#define MODE_CHG 0
#define MODE_SET 1

