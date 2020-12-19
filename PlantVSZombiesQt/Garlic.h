#ifndef GARLIC_H
#define GARLIC_H
#include"Plants.h"

class Garlic: public plant
{
public:
    Garlic(int _row,int _col,int _x, int _y) :
        plant("garlic",_row,_col, _x, _y, 20, 50)
    {
    }
};

#endif // GARLIC_H
