#ifndef SUNPANEL_H
#define SUNPANEL_H

#include"Common.h"


class SunPanel:public QGraphicsItem
{
private:
    QPixmap panel;
public:
    SunPanel();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

};

#endif // SUNPANEL_H
