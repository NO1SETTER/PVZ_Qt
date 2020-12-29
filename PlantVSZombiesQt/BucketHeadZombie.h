#ifndef BUCKETHEADZOMBIE_H
#define BUCKETHEADZOMBIE_H
#include"Zombies.h"

class BucketHeadZombie:public zombie
{
public:
    BucketHeadZombie(int _row,int _x,int _y):
        zombie("bucketheadzombie",_row,_x,_y-30,40,1,2,3)
    {
        change_state = 0;
    }
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
private:
    bool change_state;
};
#endif // BUCKETHEADZOMBIE_H
