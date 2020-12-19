#pragma once
#include "Bullet.h"
#include "Common.h"

class PumpkinHead;
class plant:public QGraphicsItem
{
protected:
    const int row,col;
    int  x, y;
    int width,height;
	int health;
    QMovie* plantGif;
    PumpkinHead* ppk;//南瓜头指针
public:
	plant();
    plant(QString _name,int _row,int _col,int _x,int _y,int _health,int _cost);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    int type()const override;
    void setGif(QString GifPath);
    void setRect(int _left,int _top,int _width,int _height);

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
    QMovie* ppkBack;
    QMovie* ppk1;
    QMovie* ppk2;
    QMovie* ppk3;
};























