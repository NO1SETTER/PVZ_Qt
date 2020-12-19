#include"Cards.h"

Card::Card()
{

}

Card::Card(int _id)
{
    id = _id;
    QString cardPath = "images/Card/Plants/"+plantName[id]+".png";
    QString plantPath = "images/Plants/"+plantName[id]+"/"+plantName[id]+".gif";
    cardPic = QPixmap(cardPath);
    plantPic = QPixmap(plantPath);
    CD = CDcounter = plantCD[_id];
}

void Card::advance(int phase)
{
    if(!phase) return;
    if(CDcounter < CD) CDcounter = CDcounter + 1;
}

bool Card::available()
{
    return CD == CDcounter;
}

void Card::resetCD()
{
    CDcounter =0;
}

void Card::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawPixmap(QRect(0,id*55,100,60),cardPic);

    if(!available())
    {
        QFont font;
        font.setPointSizeF(15);
        font.setFamily("SimHei");
        painter->setFont(font);
        painter->drawText(QRectF(80,id*55+5,20,15), Qt::AlignCenter, "CD");
    }
}

QRectF Card::boundingRect() const
{
    return QRect(0,id*55,100,60); //设置触发的区域
}

void Card::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    setCursor(Qt::ArrowCursor);
}

void Card::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (QLineF(event->screenPos(), event->buttonDownScreenPos(Qt::LeftButton)).length()
            < QApplication::startDragDistance())
        return;
    QDrag *drag = new QDrag(event->widget());
    QMimeData *mime = new QMimeData;
    mime->setText(plantName[id]);//传递card标识信息
    mime->setImageData(plantPic);
    drag->setMimeData(mime);
    drag->setPixmap(plantPic.scaled(plantWidth[id], plantHeight[id]));
    drag->setHotSpot(QPoint(35, 35));
    drag->exec();
    setCursor(Qt::ArrowCursor);
}

void Card::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    setCursor(Qt::ArrowCursor);
}
