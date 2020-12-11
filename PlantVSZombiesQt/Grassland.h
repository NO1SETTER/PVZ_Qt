#pragma once
#include<conio.h>
#include<windows.h>
#include"Color.h"
#include"Common.h"
#include"Plants.h"

// h:9 w:14
class Grassland:public QGraphicsItem //Grassland不重写paint函数,它不输出图片
{
public:
	Grassland();
	Grassland(int _x, int _y);
private:
    int x, y;//在草地中的坐标
    int width,height;
    bool dragOver;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)override;
    QRectF boundingRect() const override;
    void dragEnterEvent(QGraphicsSceneDragDropEvent *event) override;
    void dragLeaveEvent(QGraphicsSceneDragDropEvent *event) override;
    void dropEvent(QGraphicsSceneDragDropEvent *event) override;
    int type()const override;
};

