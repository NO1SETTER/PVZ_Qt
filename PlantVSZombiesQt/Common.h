#pragma once

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QPainter>
#include <QCursor>
#include <QApplication>
#include <QDrag>
#include <QMimeData>
#include <QMovie>
#include <QTimer>
#include <QGraphicsSceneMouseEvent>

#include <iostream>
#include<conio.h>
#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>
#include <algorithm>
using namespace std;
#define INRANGE(x,y) ((x>=0)&&(x<=4)&&(y>=0)&&(y<=9))
#define PRINT_SPACE_START {0,0}
#define PRINT_SPACE_SHOP  {0,42}
#define PRINT_SPACE_PLANT(x) {(short)plantNameLen[i],42}
#define PRINT_SPACE_CD(X)	 {(short)(plantNameLen[i]+1),43}
#define PRINT_SPACE_MESSAGE {0,44}
#define PRINT_SPACE_SUN {0,41}
#define PRINT_SPACE_POINT {30,41}
#define PRINT_SPACE_TIMECT {60,41}

#define KEY_CTRL -32
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ENTER 13
#define KEY_BACKSPACE 8

#define STAT_MOV  0//行进且无阻碍
#define STAT_BITE 1//有植物,停下来吃
#define STAT_WAIT 2//有僵尸,等待
//(5+1)*(8+1) --> (7+1)*(12+1)
inline short NormX(int x) { return x / 8;}
inline short NormY(int y) { return y / 13; }   //属于哪个格子
inline short LatX(int x)  {return 8*x + 1;}
inline short LatY(int y)  {return 13*y + 1;}  //属于哪个格子

class zombie;
class plant;
class bullet;

enum {KIND_PLANT,KIND_ZOMBIE,KIND_BULLET,KIND_GRASS};

extern int plantWidth[10];
extern int plantHeight[10];
extern QString plantName[10];

extern int grassX[10];
extern int grassY[6];

extern QString cardPath[10];
extern QString plantPath[10];

extern const QMap<QString,int> plantNameMap;
extern int plantNameLen[100];
extern zombie* zrec[5][10][7];
extern plant*  prec[5][10];
extern bullet* brec[42][132];//设定同一个格子至多有一个僵尸和一个植物,同一个像素点至多有一个子弹
extern int sun ;
extern int point ;
extern int timect ;
extern int curPlantNum;

#define normalPea(x,y)           PEA("豌豆",x,y,1,2)
#define icePea(x,y)              ICEPEA("冰豌豆",x,y,1,2)

enum{KIND_SF,KIND_PS,KIND_WN,KIND_IPS,KIND_DPS,KIND_SQ,KIND_HN,KIND_CB,KIND_GLC,KIND_PPK};
enum{KIND_NZ,KIND_NPZ,KIND_PVZ,KIND_CZ,KIND_CPZ,KIND_BB};
void fail();
