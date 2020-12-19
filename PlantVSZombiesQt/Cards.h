#ifndef CARDS_H
#define CARDS_H
#include"Common.h"
#include"Grassland.h"

class Card: public QGraphicsItem
{
private:
    int id;
    QPixmap cardPic;
    QPixmap plantPic;
    int CD;
    int CDcounter;
public:
    Card();
    Card(int _id);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void advance(int phase) override;
    friend class Grassland;

    bool available();
    void resetCD();
};

extern QString cardPath[10];
extern QString plantPath[10];
#endif // CARDS_H
