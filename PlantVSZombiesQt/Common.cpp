#include"Common.h"


int plantWidth[10]={80,80,75,80,80,75,70,90,65,80};
int plantHeight[10]={80,80,80,80,80,80,100,70,70,50};

int grassX[10]={250,330,410,495,580,660,740,810,900,990};
int grassY[6]={80,180,280,375,470,570};

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
void fail()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, PRINT_SPACE_MESSAGE);
	printf("[ÏûÏ¢]: ZOMBIES EAT YOUR BRAIN!!!!!");
	exit(0);
}

