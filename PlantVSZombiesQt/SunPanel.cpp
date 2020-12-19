#include"SunPanel.h"
#include<QPainter>


SunPanel::SunPanel()
{
    panel=QPixmap("images/interface/SunBack.png");
}

void SunPanel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawPixmap(QRect(100,0,160,40),panel);
    QFont font;
    font.setPointSizeF(15);
    font.setFamily("SimHei");
    painter->setFont(font);
    painter->drawText(QRectF(120,5,140,25), Qt::AlignCenter, QString::number(sun));
}

QRectF SunPanel::boundingRect() const{
    return QRectF(100,0,160,40);
}
