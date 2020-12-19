#ifndef TALLNUT_H
#define TALLNUT_H
#include"Plants.h"

class TallNut: public plant
{
public:
    TallNut(int _row,int _col,int _x, int _y) :
        plant("tallnut",_row,_col, _x, _y, 500, 125)
    {
        status = STAT1;
    }
    void advance(int phase) override;

private:
    int status;
};
#endif // TALLNUT_H

