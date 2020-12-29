#ifndef CONEHEADZOMBIE_H
#define CONEHEADZOMBIE_H
#include"Zombies.h"

class ConeHeadZombie:public zombie
{
public:
    ConeHeadZombie(int _row,int _x,int _y):
        zombie("coneheadzombie",_row,_x,_y-30,20,1,2,2)
    {
        change_state = 0;
    }
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
private:
    bool change_state;
};
#endif // CONEHEADZOMBIE_H
