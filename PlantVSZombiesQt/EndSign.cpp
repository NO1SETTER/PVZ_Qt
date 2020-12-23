#include"EndSign.h"
EndSign::EndSign()
{
    QString endsignPath = "images/ZombiesWon.png";
    pix = QPixmap(endsignPath);
}

QRectF EndSign::boundingRect() const
{
    return QRectF(200,400,300,300);
}

void EndSign::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawPixmap(QRect(400,200,300,300),pix);
}
