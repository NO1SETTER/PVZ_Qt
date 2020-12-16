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
130*40�Ļ���
***************
*		 *
*�㶹���� *
*	     *
* 		 *
* 		 *
**************
������������,�ֽ��߲������,ÿһ������(����߽�)��5*8�Ĵ�С,�ܹ���5*10����
*/
//�涨ÿ��������ո�Ϊһ���ƶ���λ
zombie* zrec[5][10][7];//ͬһ����������߸���ʬ
plant*  prec[5][10];
bullet* brec[42][132];//ͬһ��1��������4���ӵ�,����һ������û��ʵ������,�����ڵ�һ������ʵ��
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
	int current = -1;//��ǰѡ��ֲ�������
	bool ingrass = 1;//����Ƿ��ڲݵ���
	COORD precdn = { 0,0 };
	SetConsoleCursorPosition(hOut, {NormX(0),NormY(0)});
	//cdn����ʱ�������λ�õ�,nowcdn�����ڼ�¼��ǰλ�õ�
	while (1)
	{
		char ch='\0';
		duration<double> time_span;
		do {
			nowtime = steady_clock::now();
			time_span = duration_cast<duration<double>>(nowtime - pretime);
		} while ((time_span.count()<0.5)&&(!_kbhit()));//��ʱ���ڵ����߰��°���
		if (_kbhit())	ch = _getch();
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		GetConsoleScreenBufferInfo(hOut, &csbi);
		COORD nowcdn=csbi.dwCursorPosition;//��ʼʱ������һ�ε�λ��
		if (nowcdn.X == 0 && nowcdn.Y == 0)
			nowcdn={1,1};
		
		
		if (ch)//�а��°���,���°������µ���Ϣ����,������¶��������������
		{
			if (ch == 'b' && status == VACANT)
			{
				status = CHOOSE_PLANT;
				mprintf("ѡ��ֲ��");
			}
			else if (ch == KEY_CTRL)//��ͷ
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
				}//����cdn��x,y��Lat��x,y�Ƿ���
			}
			else if (ch == KEY_ENTER)
			{
				if (current == -1)
				{
					warprintf("δѡ��ֲ��\n");
				}
				else
				{
					int nowx = NormX(nowcdn.Y);//����ҲҪ��
					int nowy = NormY(nowcdn.X);
					if (!INRANGE(nowx, nowy))
					{
						warprintf("��ֲ�ڲ��Ϸ���λ��");
					}
					else if (prec[nowx][nowy] != NULL && current != KIND_PPK && prec[nowx][nowy]->kind != KIND_PPK)
					{
						warprintf("����������Ѿ���ֲ����!");
					}
					else if (sun < plantCost[current])
					{
						warprintf("û���㹻������!");
					}
					else if (CDcounter[current]<plantCD[current])
					{
						warprintf("ֲ����ȴ��");
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
									{	warprintf("�������Ϲ�ͷ����ֲ�Ϲ�ͷ!");
									}
									else if(plt->addPumpkin(new pumpkin(nowx, nowy) ) == 0)
									{	warprintf("��ֲ���������Ϲ�ͷ");
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
			else if ((ch >= '0' && ch <= '9') && (status == CHOOSE_PLANT || status == CHOOSE_SPACE))//�ݶ������10��ֲ��
			{
				if (ch - '0' < curPlantNum)
				{
					current = ch - '0';
					status = CHOOSE_SPACE;
				}

			}
			else if (ch == KEY_BACKSPACE)
			{
				int nowx = NormX(nowcdn.Y);//����ҲҪ��
				int nowy = NormY(nowcdn.X);
				if (!prec[nowx][nowy])
				{
					warprintf("��ǰλ��û����ֲֲ��");
				}
				else
					prec[nowx][nowy] = NULL;
			}
			else;
		}//��������
		else //ʱ�Ӵ���
		{

			//Update Zombies
			for(int j = 0 ;j < 10; j++) //��ʬ�������Ҹ���
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
			for(int j = 129; j >= 0; j--) //�ӵ������������
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
		//��ʾ(����)���ȼ� ��ʬ>ֲ��>�ӵ�>���
				//Print Frame/Information
				HideCursor();
				SetConsoleCursorPosition(hOut, PRINT_SPACE_SUN);
				printf("����:%d       ", sun);
				SetConsoleCursorPosition(hOut, PRINT_SPACE_POINT);
				printf("����:%d       ", point);
				SetConsoleCursorPosition(hOut, PRINT_SPACE_TIMECT);
				printf("ʱ��:%d       ", timect / 2);
				SetConsoleCursorPosition(hOut, PRINT_SPACE_SHOP);
				printf("[�̵�]:");
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

