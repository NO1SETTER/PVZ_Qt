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

#define STAT_MOV  0//�н������谭
#define STAT_BITE 1//��ֲ��,ͣ������
#define STAT_WAIT 2//�н�ʬ,�ȴ�

class zombie;
class plant;
class bullet;

enum {KIND_PLANT,KIND_ZOMBIE,KIND_BULLET,KIND_GRASS,KIND_SHOVEL};

//ֲ�����Ϣ
extern int plantWidth[10];
extern int plantHeight[10];
extern QString plantName[10];
extern const QMap<QString,int> plantNameMap;
//��ʬ����Ϣ
extern int zombieWidth[5];
extern int zombieHeight[5];
extern QString zombieName[5];
extern const QMap<QString,int> zombieNameMap;

//�ݵص���Ϣ
extern int grassX[10];
extern int grassY[6];


extern int sun ;
extern int point ;
extern int timect ;
extern int curPlantNum;

void fail();
