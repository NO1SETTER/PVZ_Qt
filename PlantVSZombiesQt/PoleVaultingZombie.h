#ifndef POLEVAULTINGZOMBIE_H
#define POLEVAULTINGZOMBIE_H
#include"Zombies.h"

class PoleVaultingZombie :public zombie
{
public:
    PoleVaultingZombie(int _row,int _x, int _y) :
        zombie("polevaultingzombie",_row, _x, _y-120,15,1,3,2)
    {
        Pole=1;
        isTallNut = 0;
        jumpCounter = -1;
        width = 110;
        height = 140;
    }
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    bool HasPole() {return Pole;}
    void advance(int phase) override;

    static int jumpTime1;
    static int jumpTime2;
private:
    bool Pole;
    bool isTallNut;
    int  jumpCounter;
};

#endif // POLEVAULTINGZOMBIE_H
