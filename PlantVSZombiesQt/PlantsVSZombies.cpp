// PlantsVSZombies.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include"Zombies.h"
#include"Plants.h"
#include"Common.h"
#include"Grassland.h"

#include<chrono>
#include<stdio.h>
#include<string>
using namespace std;
using namespace std::chrono;
/*
130*40的画幅
***************
*		 *
*豌豆射手 *
*	     *
* 		 *
* 		 *
**************
按照如上排列,分界线不算距离,每一个格子(不算边界)是5*8的大小,总共是5*10格子
*/
//规定每两个输出空格为一个移动单位
zombie* zrec[5][10][7];//同一个格子最多七个僵尸
plant*  prec[5][10];
bullet* brec[42][132];//同一个1上最多会有4颗子弹,但是一个格子没有实际意义,格子内的一个点有实际
Grassland* grass[5][10];

int plantNameLen[100];
int plantCost[20] = { 50,100,50,175,200,50,125,150,50,125};
int unlockThreshold[20] = { 0,0,0,10,1000,10000000,10000000,1000000000,100000000,100000000,1000000000,100000000 };
const int plantCD[20] = {4,8,20,12,12,20,30,30,20,16};
int CDcounter[20] = { 4,8,20,12,12,20,30,30,20,16 };

int sun = 50;
int point = 0;
int timect = 0;
int curPlantNum = 10;

enum { VACANT, CHOOSE_PLANT, CHOOSE_SPACE };
int status = VACANT;
/*
int main()
{
	srand((int)time(0));
	SetConsoleTitleA("Plants VS Zombie by zyx");
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleScreenBufferSize(hOut, {200,200});
	SMALL_RECT rc = { 0,0,149,59 };
	assert(SetConsoleWindowInfo(hOut, true, &rc));
	steady_clock::time_point pretime = steady_clock::now();
	steady_clock::time_point nowtime = steady_clock::now();

	memset(zrec, 0, sizeof(zrec));
	memset(prec, 0, sizeof(prec));
	memset(brec, 0, sizeof(brec));
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 10; j++)
			grass[i][j] = new Grassland(i,j);

	plantNameLen[0] = 7;
	for (int i = 1; i <= 9; i++)
	{
		plantNameLen[i] = plantNameLen[i - 1] + strlen(plantName[i - 1]) + (to_string(plantCost[i-1])).length() + 4;
	}
	int current = -1;//当前选中植物的种类
	bool ingrass = 1;//光标是否在草地内
	COORD precdn = { 0,0 };
	SetConsoleCursorPosition(hOut, {NormX(0),NormY(0)});
	//cdn是临时调整输出位置的,nowcdn是用于记录此前位置的
	while (1)
	{
		char ch='\0';
		duration<double> time_span;
		do {
			nowtime = steady_clock::now();
			time_span = duration_cast<duration<double>>(nowtime - pretime);
		} while ((time_span.count()<0.5)&&(!_kbhit()));//计时周期到或者按下按键
		if (_kbhit())	ch = _getch();
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		GetConsoleScreenBufferInfo(hOut, &csbi);
		COORD nowcdn=csbi.dwCursorPosition;//开始时保存上一次的位置
		if (nowcdn.X == 0 && nowcdn.Y == 0)
			nowcdn={1,1};
		
		
		if (ch)//有按下按键,按下按键导致的信息更新,输出更新都必须在祠内完成
		{
			if (ch == 'b' && status == VACANT)
			{
				status = CHOOSE_PLANT;
				mprintf("选择植物");
			}
			else if (ch == KEY_CTRL)//箭头
			{
				switch (_getch())
				{
				case KEY_UP:
					if (nowcdn.Y >= 8 && ingrass)
						nowcdn.Y = LatX(NormX(nowcdn.Y) - 1);
					else if (!ingrass)
					{
						ingrass = 1;
						nowcdn = precdn;
					}
					break;
				case KEY_DOWN:
					if (nowcdn.Y <= 32 && ingrass)
						nowcdn.Y = LatX(NormX(nowcdn.Y) + 1);
					else if (ingrass)
					{
						ingrass = 0;
						if (current == -1) current = 0;
						precdn = nowcdn;
					}
						break;
				case KEY_LEFT:
					if (nowcdn.X >= 13 && ingrass)
						nowcdn.X = LatY(NormY(nowcdn.X) - 1);
					else if (!ingrass && current)
						current = current - 1;
					break;
				case KEY_RIGHT:
					if (nowcdn.X <= 116 && ingrass)
						nowcdn.X = LatY(NormY(nowcdn.X) + 1);
					else if (!ingrass && current < curPlantNum - 1)
						current = current + 1;
					break;
				default:break;
				}//这里cdn的x,y和Lat的x,y是反的
			}
			else if (ch == KEY_ENTER)
			{
				if (current == -1)
				{
					warprintf("未选择植物\n");
				}
				else
				{
					int nowx = NormX(nowcdn.Y);//这里也要反
					int nowy = NormY(nowcdn.X);
					if (!INRANGE(nowx, nowy))
					{
						warprintf("种植在不合法的位置");
					}
					else if (prec[nowx][nowy] != NULL && current != KIND_PPK && prec[nowx][nowy]->kind != KIND_PPK)
					{
						warprintf("这个格子里已经有植物了!");
					}
					else if (sun < plantCost[current])
					{
						warprintf("没有足够的阳光!");
					}
					else if (CDcounter[current]<plantCD[current])
					{
						warprintf("植物冷却中");
					}
					else
					{
						sun = sun - plantCost[current];
						CDcounter[current] = 0;
						plant* plt = prec[nowx][nowy];
						switch (current)
						{
						case 0:prec[nowx][nowy] = new sunFlower(nowx, nowy); 
							prec[nowx][nowy]->addPumpkin(dynamic_cast<PUMPKIN*>(plt)); break;
						case 1:prec[nowx][nowy] = new peaShooter(nowx, nowy); 
							prec[nowx][nowy]->addPumpkin(dynamic_cast<PUMPKIN*>(plt)); break;
						case 2:prec[nowx][nowy] = new wallNut(nowx, nowy); 
							prec[nowx][nowy]->addPumpkin(dynamic_cast<PUMPKIN*>(plt)); break;
						case 3:prec[nowx][nowy] = new icePeaShooter(nowx, nowy); 
							prec[nowx][nowy]->addPumpkin(dynamic_cast<PUMPKIN*>(plt)); break;
						case 4:prec[nowx][nowy] = new doublePeaShooter(nowx, nowy); 
							prec[nowx][nowy]->addPumpkin(dynamic_cast<PUMPKIN*>(plt)); break;
						case 5:prec[nowx][nowy] = new squash(nowx, nowy); 
							prec[nowx][nowy]->addPumpkin(dynamic_cast<PUMPKIN*>(plt)); break;
						case 6:prec[nowx][nowy] = new highNut(nowx, nowy); 
							prec[nowx][nowy]->addPumpkin(dynamic_cast<PUMPKIN*>(plt)); break;
						case 7:prec[nowx][nowy] = new cherryBomb(nowx, nowy); 
							prec[nowx][nowy]->addPumpkin(dynamic_cast<PUMPKIN*>(plt)); break;
						case 8:prec[nowx][nowy] = new garlic(nowx, nowy);
							prec[nowx][nowy]->addPumpkin(dynamic_cast<PUMPKIN*>(plt)); break;
						case 9:if (plt)
								{
									if (plt->kind == KIND_PPK)
									{	warprintf("不能在南瓜头上种植南瓜头!");
									}
									else if(plt->addPumpkin(new pumpkin(nowx, nowy) ) == 0)
									{	warprintf("该植物上已有南瓜头");
									}
								break;
								}
							 else
								prec[nowx][nowy] = new pumpkin(nowx, nowy);
							
							break;
						default:break;
						}
					}
				}
			}
			else if (ch == 'x')
			{
				status = VACANT;
				current = -1;
				mprintf("                                       ");
			}
			else if ((ch >= '0' && ch <= '9') && (status == CHOOSE_PLANT || status == CHOOSE_SPACE))//暂定最多有10种植物
			{
				if (ch - '0' < curPlantNum)
				{
					current = ch - '0';
					status = CHOOSE_SPACE;
				}

			}
			else if (ch == KEY_BACKSPACE)
			{
				int nowx = NormX(nowcdn.Y);//这里也要反
				int nowy = NormY(nowcdn.X);
				if (!prec[nowx][nowy])
				{
					warprintf("当前位置没有种植植物");
				}
				else
					prec[nowx][nowy] = NULL;
			}
			else;
		}//按键触发
		else //时钟触发
		{

			//Update Zombies
			for(int j = 0 ;j < 10; j++) //僵尸从左向右更新
				for (int i = 0; i < 5; i++)
					for (int k = 0; k < 5; k++)
					{
						if (zrec[i][j][k])
						{
							if (!zrec[i][j][k]->func())
							{	
								if (zrec[i][j][k]->status == STAT_BITE)
								{
									if (INRANGE(i, j - 1) && prec[i][j - 1])
									{
										zrec[i][j][k]->bite(prec[i][j - 1]);
									}
									else
									{
										zrec[i][j][k]->status = STAT_MOV;
										zrec[i][j][k]->move();
									}
								}
								else if (zrec[i][j][k]->status == STAT_WAIT)
								{
									if (j == 0)
										zrec[i][j][k]->status = STAT_MOV;
									else if (INRANGE(i, j - 1) && (findZombieSpace(i, j - 1) != -1))
										zrec[i][j][k]->status = STAT_MOV;
									if (zrec[i][j][k]->status == STAT_MOV)
										zrec[i][j][k]->move();
								}
								else
								{
									zrec[i][j][k]->move();
								}
							}
						}
					}
				//Generate Zombies
			if (timect > 30)
			{
				int row = rand() % 5;
				int no = findZombieSpace(row, 9);
				if (no != -1)
					zrec[row][9][no] = generateZombies(20, 0, row, no);
			}

			//Update Bullets
			for(int j = 129; j >= 0; j--) //子弹从右向左更新
				for (int i = 0; i <40; i++) {
						zombie* zb = NULL;
						bullet* blt = brec[i][j];
						int kind = -1;
						if (blt)
						{
							kind = blt->kind;
							zb = blt->move();
						}
						if (zb)
						{
							if (kind == 0)
							{
								PEA* bul = static_cast<PEA*>(blt);
								bul->explode(zb);
							}
							else if (kind == 1)
							{
								ICEPEA* bul = static_cast<ICEPEA*>(blt);
								bul->explode(zb);
							}
							else;
						}
				}

			//Update Plants
			for(int j = 9; j >= 0 ; j--)
				for (int i = 0; i < 5; i++)
					if (prec[i][j])
						prec[i][j]->func();
			//Update Information
				pretime = nowtime;
				if (point >= unlockThreshold[curPlantNum])
					curPlantNum = curPlantNum + 1;
				timect = timect +1;
				if (timect % 10 == 0)
					sun = sun + 25;
				for (int i = 0; i < curPlantNum; i++)
					if (CDcounter[i] < plantCD[i])
						CDcounter[i] += 1;

			
		}
		//Print Screen
		//显示(覆盖)优先级 僵尸>植物>子弹>框架
				//Print Frame/Information
				HideCursor();
				SetConsoleCursorPosition(hOut, PRINT_SPACE_SUN);
				printf("阳光:%d       ", sun);
				SetConsoleCursorPosition(hOut, PRINT_SPACE_POINT);
				printf("积分:%d       ", point);
				SetConsoleCursorPosition(hOut, PRINT_SPACE_TIMECT);
				printf("时间:%d       ", timect / 2);
				SetConsoleCursorPosition(hOut, PRINT_SPACE_SHOP);
				printf("[商店]:");
				for (int i = 0; i < curPlantNum; i++)
				{
					SetConsoleCursorPosition(hOut, PRINT_SPACE_PLANT(i));
					if (i == current)
						printf("%s[%s:%d]" ANSI_RESET,plantColor[i],plantName[i],plantCost[i]);
					else
						printf("[%s:%d]", plantName[i], plantCost[i]);
					SetConsoleCursorPosition(hOut, PRINT_SPACE_CD(i));
					printf("%d  ", (plantCD[i] - CDcounter[i]) / 2);
				}
				
				for (int i = 0; i < 5; i++)
					for (int j = 0; j < 10; j++)
					{
						grass[i][j]->printFrame();
						bool aim = 0;
						if (NormX(nowcdn.Y) == i && NormY(nowcdn.X) == j) aim = 1;
						if (findZombie(i, j) != -1)
							grass[i][j]->printZombie(aim);
						else if (prec[i][j])
							grass[i][j]->printPlant(aim);
						else
							grass[i][j]->printBullet(aim);
					}
				ShowCursor();
				SetConsoleCursorPosition(hOut, nowcdn);
	}
	CloseHandle(hOut);
}*/

