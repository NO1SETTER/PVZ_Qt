#ifndef PEABULLET_H
#define PEABULLET_H

#include"Bullet.h"


class PeaBullet :public bullet
{
public:
    PeaBullet(int _row, int _x, int _y) :
        bullet("peabullet",_row,_x,_y,1,5)
    {
    }
};
#endif // PEABULLET_H
