#ifndef BUCKETHEADZOMBIE_H
#define BUCKETHEADZOMBIE_H
#include"Zombies.h"

class BucketHeadZombie:public zombie
{
public:
    BucketHeadZombie(int _row,int _x,int _y):
        zombie("bucketheadzombie",_row,_x,_y-30,40,1,2,3)
    {
    }
};
#endif // BUCKETHEADZOMBIE_H
