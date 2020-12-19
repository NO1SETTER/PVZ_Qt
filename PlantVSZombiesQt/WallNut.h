#ifndef WALLNUT_H
#define WALLNUT_H
#include"Plants.h"

class WallNut : public plant
{
public:
    WallNut(int _row,int _col,int _x, int _y) :
        plant("wallnut",_row,_col,_x, _y,350 ,50)
    {
        status = STAT1;
    }
    void advance(int phase) override;

private:
    int status;
};
#endif // WALLNUT_H
