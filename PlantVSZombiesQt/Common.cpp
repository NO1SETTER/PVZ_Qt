#include"Common.h"


int plantWidth[10]={80,80,75,80,80,75,70,90,65,80};
int plantHeight[10]={80,80,80,80,80,80,100,70,70,50};
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

int zombieWidth[5]={105,105,105,105,105};
int zombieHeight[5]={120,135,135,120,120};
QString zombieName[5]={
    "zombie",
    "coneheadzombie",
    "bucketheadzombie",
    "flagzombie",
    "polevaultingzombie"
};

const QMap<QString,int> zombieNameMap={
    {"zombie",0},
    {"coneheadzombie",1},
    {"bucketheadzombie",2},
    {"flagzombie",3},
    {"polevaultingzombie",4},
};

int grassX[10]={250,330,410,495,580,660,740,810,900,990};
int grassY[6]={80,180,280,375,470,570};
void fail()
{
	exit(0);
}

