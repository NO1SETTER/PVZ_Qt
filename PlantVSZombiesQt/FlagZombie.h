#ifndef FLAGZOMBIE_H
#define FLAGZOMBIE_H
#include"Zombies.h"

class FlagZombie:public zombie
{
public:
    FlagZombie(int _row,int _x,int _y):
        zombie("flagzombie",_row,_x,_y-40,10,1,1,1)
    {

    }
};
#endif // FLAGZOMBIE_H

