#include"Shovel.h"
QString shovelPath = "images/interface/Shovel.png";
QString shovelBackPath = "images/interface/ShovelBack.png";

Shovel::Shovel()
{
    shovelPic = QPixmap(shovelPath);
    shovelBackPic = QPixmap(shovelBackPath);
}

QRectF Shovel::boundingRect() const
{
    return QRect(360,0,100,60); //设置触发的区域
}

void Shovel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawPixmap(QRect(360,0,100,60),shovelBackPic);
    painter->drawPixmap(QRect(370,10,80,40),shovelPic);

}

void Shovel:: mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    setCursor(Qt::ArrowCursor);
}

void Shovel::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (QLineF(event->screenPos(), event->buttonDownScreenPos(Qt::LeftButton)).length()
            < QApplication::startDragDistance())
        return;
    QDrag *drag = new QDrag(event->widget());
    QMimeData *mime = new QMimeData;
    QImage image("images/interface/Shovel.png");
    mime->setText("shovel");
    mime->setImageData(image);
    drag->setMimeData(mime);
    drag->setPixmap(QPixmap::fromImage(image).scaled(80, 40));
    drag->setHotSpot(QPoint(35, 35));
    drag->exec();
    scene();
    setCursor(Qt::ArrowCursor);
}

void Shovel::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    setCursor(Qt::ArrowCursor);
}

void Shovel::remove(const QPoint &pos)
{
    QList<QGraphicsItem*> nowitems = scene()->items(pos);
    for(auto it=nowitems.begin();it!=nowitems.end();it++)
    {
        if((*it)->type() == KIND_PLANT)
        {
            delete *it;
            return;
        }
    }
}
