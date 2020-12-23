#ifndef ENDSIGN_H
#define ENDSIGN_H
#include "Common.h"

class EndSign:public QGraphicsItem
{
public:
    EndSign();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
private:
    QPixmap pix;
};
#endif // ENDSIGN_H
