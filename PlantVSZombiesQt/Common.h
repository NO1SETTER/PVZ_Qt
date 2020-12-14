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

class zombie;
class plant;
class bullet;

enum {KIND_PLANT,KIND_ZOMBIE,KIND_BULLET,KIND_GRASS,KIND_SHOVEL};

//植物的信息
extern int plantWidth[10];
extern int plantHeight[10];
extern QString plantName[10];
extern const QMap<QString,int> plantNameMap;
//僵尸的信息
extern int zombieWidth[5];
extern int zombieHeight[5];
extern QString zombieName[5];
extern const QMap<QString,int> zombieNameMap;

//草地的信息
extern int grassX[10];
extern int grassY[6];


extern int sun ;
extern int point ;
extern int timect ;
extern int curPlantNum;

void fail();
