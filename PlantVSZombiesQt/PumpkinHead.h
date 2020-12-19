#ifndef PUMPKINHEAD_H
#define PUMPKINHEAD_H
#include"Plants.h"

class PumpkinHead :public plant
{
public:
    PumpkinHead(int _row,int _col,int _x, int _y) :
        plant("pumpkinhead",_row,_col, _x, _y, 250, 125)
    {
        protector=NULL;
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void setProtector(plant* plt);
    void removeProtector();

    friend class plant;
private:
    plant* protector;//记录被保护的
    void dead() override;
};

#endif // PUMPKINHEAD_H
