#ifndef CHERRYBOMB_H
#define CHERRYBOMB_H

#include"Plants.h"

class CherryBomb : public plant
{
public:
    CherryBomb(int _row,int _col,int _x, int _y):
        plant("cherrybomb",_row,_col, _x, _y, 10000, 150)
    {
        bombCounter = -1;
        status = STAT1;
    }
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    void advance(int phase) override;
private:
    QList<QGraphicsItem*> WipeOutList;
    int bombCounter;
    int status;
};

#endif // CHERRYBOMB_H
