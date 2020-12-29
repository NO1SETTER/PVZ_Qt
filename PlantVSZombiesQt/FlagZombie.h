#ifndef FLAGZOMBIE_H
#define FLAGZOMBIE_H
#include"Zombies.h"

class FlagZombie:public zombie
{
public:
    FlagZombie(int _row,int _x,int _y):
        zombie("flagzombie",_row,_x,_y-40,10,1,2,1)
    {

    }
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)override;
};
#endif // FLAGZOMBIE_H

