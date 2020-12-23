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
#define STAT_JUMP1 3
#define STAT_JUMP2 4//���ڳŸ�����ʬ������״̬

#define STAT1 0
#define STAT2 1
#define STAT3 2//������̬�仯��ֲ���õ�

class zombie;
class plant;
class bullet;
class Card;
enum {KIND_PLANT,KIND_ZOMBIE,KIND_BULLET,KIND_GRASS,KIND_SHOVEL};


//ֲ�����Ϣ
extern int plantWidth[10];
extern int plantHeight[10];
extern QString plantName[10];
extern const QMap<QString,int> plantNameMap;
extern int plantCD[10];
//��ʬ����Ϣ
extern int zombieWidth[5];
extern int zombieHeight[5];
extern QString zombieName[5];
extern const QMap<QString,int> zombieNameMap;
extern int zombieAttackWidth[5];
extern int zombieAttackHeight[5];
//�ӵ�����Ϣ
extern int bulletWidth[2];
extern int bulletHeight[2];
extern QString bulletName[2];
extern const QMap<QString,int> bulletNameMap;
//�ݵص���Ϣ
extern int grassX[10];
extern int grassY[6];
//��Ƭ����Ϣ
extern Card* cards[10];
//�˴���PVZ��PoleVaultingZombie..
#define PVZ_JUMP1_WIDTH 280
#define PVZ_JUMP1_HEIGHT 210
#define PVZ_JUMP2_WIDTH 240
#define PVZ_JUMP2_HEIGHT 210
#define PVZ_WALKING_WIDTH 320
#define PVZ_WALKING_HEIGHT 210

extern int sun;
extern int point ;

