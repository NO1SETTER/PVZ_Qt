#ifndef SNOWPEA_H
#define SNOWPEA_H
#include"Plants.h"

class SnowPea :public plant
{
public:
    void advance(int phase)override;
    SnowPea(int _row,int _col,int _x, int _y) :
        plant("snowpea",_row,_col, _x, _y,40 ,175)
    {
        counter = 0;
    }
    int counter;
};

#endif // SNOWPEA_H
