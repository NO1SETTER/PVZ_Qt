#ifndef SNOWPEABULLET_H
#define SNOWPEABULLET_H

#include"Bullet.h"

class SnowPeaBullet :public bullet
{
public:
    void advance(int phase) override;
    SnowPeaBullet(int _row, int _x, int _y) :
        bullet("snowpeabullet",_row,_x,_y,1,5)
    {
    }
};
#endif // SNOWPEABULLET_H
