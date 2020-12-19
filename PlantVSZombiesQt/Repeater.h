#ifndef REPEATER_H
#define REPEATER_H
#include"Plants.h"

class Repeater :public plant
{
public:
    void advance(int phase)override;
    Repeater(int _row,int _col,int _x, int _y) :
        plant("repeater",_row,_col, _x ,_y,40 ,200)
    {
        counter = 0;
    }
    int counter;
};
#endif // REPEATER_H

