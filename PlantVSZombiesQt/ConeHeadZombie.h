#ifndef CONEHEADZOMBIE_H
#define CONEHEADZOMBIE_H
#include"Zombies.h"

class ConeHeadZombie:public zombie
{
public:
    ConeHeadZombie(int _row,int _x,int _y):
        zombie("coneheadzombie",_row,_x,_y-30,20,1,1,2)
    {
    }
};
#endif // CONEHEADZOMBIE_H
