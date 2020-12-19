#ifndef PEASHOOTER_H
#define PEASHOOTER_H
#include"Plants.h"

class PeaShooter :public plant
{
public:
    void advance(int phase)override;
    PeaShooter(int _row,int _col,int _x, int _y) :
        plant("peashooter",_row,_col, _x, _y,40,100)
    {
        counter = 0;
    }
    int counter;
};
#endif // PEASHOOTER_H
