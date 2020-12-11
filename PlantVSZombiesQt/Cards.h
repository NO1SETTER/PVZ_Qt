#ifndef CARDS_H
#define CARDS_H
#include"Common.h"

class Card: public QGraphicsItem
{
private:
    int id;
    QPixmap cardPic;
    QPixmap plantPic;
public:
    Card();
    Card(int _id);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
};

extern QString cardPath[10];
extern QString plantPath[10];
#endif // CARDS_H
