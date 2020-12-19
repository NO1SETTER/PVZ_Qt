#ifndef NORMALZOMBIE_H
#define NORMALZOMBIE_H
#include"Zombies.h"
class NormalZombie:public zombie
{
public:
    NormalZombie(int _row,int _x,int _y):
        zombie("normalzombie",_row,_x,_y-10,10,1,1,1)
    {
    }

};
#endif // NORMALZOMBIE_H
