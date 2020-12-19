#include"Common.h"


int plantWidth[10]={80,80,75,80,80,75,70,90,65,90};
int plantHeight[10]={80,80,80,80,80,80,100,70,70,60};
QString plantName[10]={
    "sunflower",
    "peashooter",
    "wallnut",
    "snowpea",
    "repeater",
    "squash",
    "tallnut",
    "cherrybomb",
    "garlic",
    "pumpkinhead",
};
const QMap<QString,int> plantNameMap={
    {"sunflower",0},
    {"peashooter",1},
    {"wallnut",2},
    {"snowpea",3},
    {"repeater",4},
    {"squash",5},
    {"tallnut",6},
    {"cherrybomb",7},
    {"garlic",8},
    {"pumpkinhead",9}
};
int plantCD[10]={50,50,200,50,50,250,300,300,100,200};

int zombieWidth[5]={95,95,100,115,200};
int zombieHeight[5]={120,135,135,145,230};
QString zombieName[5]={
    "normalzombie",
    "coneheadzombie",
    "bucketheadzombie",
    "flagzombie",
    "polevaultingzombie"
};
const QMap<QString,int> zombieNameMap={
    {"normalzombie",0},
    {"coneheadzombie",1},
    {"bucketheadzombie",2},
    {"flagzombie",3},
    {"polevaultingzombie",4},
};
int zombieAttackWidth[5]={90,90,120,105,300};
int zombieAttackHeight[5]={120,130,135,140,210};

int bulletWidth[2]={40,40};
int bulletHeight[2]={25,25};
QString bulletName[2]={
    "peabullet",
    "snowpeabullet"
};
const QMap<QString,int> bulletNameMap={
    {"peabullet",0},
    {"snowpeabullet",1}
};

Card* cards[10];

int grassX[10]={250,330,410,495,580,660,740,810,900,990};
int grassY[6]={80,180,280,375,470,570};

int sun = 5000;
int point = 0;
void fail()
{
	exit(0);
}

