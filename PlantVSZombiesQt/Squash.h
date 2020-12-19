#ifndef SQUASH_H
#define SQUASH_H
#include"Plants.h"

class Squash : public plant
{
public:
    Squash(int _row,int _col,int _x, int _y) :
        plant("squash",_row,_col, _x, _y, 100000, 50)
    {
        status =STAT1;
        attackCounter = -1;
    }
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    void advance(int phase) override;

private:
    QList<QGraphicsItem*> WipeOutList;
    int status;
    int attackCounter;
};
#endif // SQUASH_H
