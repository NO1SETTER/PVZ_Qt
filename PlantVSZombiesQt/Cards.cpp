#include"Cards.h"

QString cardPath[10]={
    "images/Card/Plants/sunFlower.png",
    "images/Card/Plants/Peashooter.png",
    "images/Card/Plants/WallNut.png",
    "images/Card/Plants/SnowPea.png",
    "images/Card/Plants/Repeater.png",
    "images/Card/Plants/Squash.png",
    "images/Card/Plants/TallNut.png",
    "images/Card/Plants/CherryBomb.png",
    "images/Card/Plants/Garlic.png",
    "images/Card/Plants/PumpkinHead.png",
};

QString plantPath[10]={
   "images/Plants/SunFLower/SunFlower.gif",
   "images/Plants/Peashooter/Peashooter.gif",
   "images/Plants/WallNut/WallNut.gif",
   "images/Plants/SnowPea/SnowPea.gif",
   "images/Plants/Repeater/Repeater.gif",
   "images/Plants/Squash/Squash.gif",
   "images/Plants/TallNut/TallNut.gif",
   "images/Plants/CherryBomb/CherryBomb.gif",
   "images/Plants/Garlic/Garlic.gif",
   "images/Plants/PumpkinHead/PumpkinHead.gif",

};

QString plantName[10]={
    "sunflower",
    "peashooter",
    "wallnut",
    "snowpea",
    "repeater",
    "squash",
    "tallnut",
    "cherrybomb",
    "garlic",
    "pumpkinhead",
};

Card::Card()
{

}

Card::Card(int _id)
{
    id = _id;
    cardPic = QPixmap(cardPath[id]);
    plantPic = QPixmap(plantPath[id]);
}

void Card::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawPixmap(QRect(0,id*55,100,60),cardPic);
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
