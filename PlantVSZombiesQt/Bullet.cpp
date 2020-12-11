#include "Bullet.h"
#include "Plants.h"
#include "Zombies.h"
#include "Color.h"

bullet::bullet():
	name("Bullet"),attack(0),speed(0),kind(-1),id(rand()%10000)
{
	x = y = 0;
}

bullet::bullet(const char* _name,const char* _color, int _x, int _y, int _kind, int _attack, int _speed) :
	name(_name),color(_color),kind(_kind),attack(_attack),speed(_speed),id(rand()%10000)
{
	x = _x;
	y = _y;
}

bullet::~bullet()
{
}

zombie* bullet::move()
{
/*
	brec[x][y] = NULL;
	int nextPos = y + speed;
    for (int i = NormY(y); i <= NormY(min(nextPos,129)); i++)
	{
		for (int no = 0; no < 7; no++)
		{
			if(zrec[NormX(x)][i][no]&&zrec[NormX(x)][i][no]->kind!=KIND_BB)
				return zrec[NormX(x)][i][no];
		}	
	}
	y = nextPos;
    if (y <= 130) brec[x][y] = this;*/
	return NULL;
}


void PEA::explode(zombie* zb)
{
	assert(zb);
	brec[x][y] = NULL;
	zb->hurt(attack);
}



void ICEPEA::explode(zombie* zb)
{
	brec[x][y] = NULL;
	zb->hurt(attack);
	zb->decelerate(1,MODE_CHG);
}




