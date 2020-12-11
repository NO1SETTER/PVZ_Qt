#pragma once
#include "Zombies.h"
#include "Common.h"
#include "color.h"

//name(_name),color(_color),kind(_kind),attack(_attack),speed(_speed),id(rand()%10000)
class bullet
{
protected:
	int x, y;//x,y均以像素点计(不然怎么转化成坐标输出啊!! )
	const int attack;
	const int speed;//子弹的速度是以像素点记的,坐标也是以像素点记的,输出时直接按像素点进行显示
    const int id;//随机产生的编号,用于标识
public:
	bullet();
	bullet(const char* _name,const char* color,int _x,int _y, int _kind,int _attack, int _speed);
	~bullet();
	zombie* move();

    const char* name;
    const char* color;
    const int kind;//用于指示派生类的类别
};

class PEA :public bullet
{
public:
	void explode(zombie* zb);
	PEA(const char* _name, int _x, int _y, int _attack, int _speed) :
		bullet(_name,ANSI_LIGHT_GREEN, _x, _y, 0, _attack, _speed)
	{
	}
};

class ICEPEA :public bullet
{
public:
	void explode(zombie* zb);
	ICEPEA(const char* _name, int _x, int _y, int _attack, int _speed) :
		bullet(_name,ANSI_LIGHT_CYAN, _x, _y, 1, _attack, _speed)
	{
	}
};

