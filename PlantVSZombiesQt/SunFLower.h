#ifndef SUNFLOWER_H
#define SUNFLOWER_H
#include"Plants.h"

class SunFLower : public plant
{
public:
    SunFLower(int _row,int _col,int _x, int _y) :
        plant("sunflower",_row,_col,_x, _y,30 , 50)
    {
        sunCounter = 0;
    }
    void advance(int phase)override;

private:
    int sunCounter;
};
#endif // SUNFLOWER_H
