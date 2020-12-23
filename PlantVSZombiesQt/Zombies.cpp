#include "Zombies.h"
#include "Plants.h"
#include "PumpkinHead.h"

zombie::zombie():
	name("Zombie"),attack(0),bonus(0),id(rand()%10000)
{
	x = 0;
	y = 0;
	health = 0;
	speed = 0;
    zombieGif = NULL;
	status = STAT_MOV;
    isVerticalWalking = 0;
}

zombie::zombie(QString _name,int _row, int _x, int _y,int _health, int _attack, int _speed,int _bonus):
    name(_name),row(_row),x(_x),y(_y),attack(_attack),bonus(_bonus),id(rand()%10000)
{
    width=zombieWidth[zombieNameMap[_name]];
    height=zombieHeight[zombieNameMap[_name]];
	health = _health;
	speed = _speed;
	status = STAT_MOV;
    zombieGif = NULL;
    QString zombiePath="images/Zombies/"+_name+"/"+_name+".gif";
    setGif(zombiePath);
    isVerticalWalking = 0;
}


QRectF zombie::boundingRect() const
{
    return QRectF(x,y,width,height);
}

void zombie::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawPixmap(QRect(x,y,width,height),zombieGif->currentPixmap());
}

bool zombie::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
   if(other->type()!=KIND_PLANT&&other->type()!=KIND_BULLET) return 0;
   if(other->type() == KIND_PLANT)
   {
       plant* frontplt =  qgraphicsitem_cast<plant*>((QGraphicsItem*)other);
       int prow =frontplt->getRow();
       int col = frontplt->getCol();
       if(row == prow &&(this->x>=grassX[col+1]-100 ) && this->x<=grassX[col+1]-20) return 1;
   }
   return 0;
}

int zombie::type()const
{
    return KIND_ZOMBIE;
}

void zombie::setGif(QString GifPath)
{
    if(zombieGif)
        delete zombieGif;
    zombieGif = NULL;
    zombieGif = new QMovie(GifPath);
    assert(zombieGif);
    zombieGif->start();
}

void zombie::setRect(int _left,int _top,int _width,int _height)
{
    x = _left;
    y = _top;
    width = _width;
    height = _height;
}

void zombie::advance(int phase)
{
   if(!phase) return;
   if(isVerticalWalking)
   {
      if(verticalSpeed > 0)
      {
          if(y + verticalSpeed < targetY) y = y + verticalSpeed;
          else
          {
              y = targetY;
              row = targetRow;
              isVerticalWalking = 0;
          }
      }
      else
      {
          if(y + verticalSpeed > targetY) y = y + verticalSpeed;
          else
          {
              y = targetY;
              row = targetRow;
              isVerticalWalking = 0;
          }
      }
   }
   QList<QGraphicsItem*> coItems=collidingItems();
   if(coItems.isEmpty())
   {
      x = x - speed;
      if(status!=STAT_MOV)
      {
          status=STAT_MOV;
          QString zombiePath="images/Zombies/"+name+"/"+name+".gif";
          setGif(zombiePath);
          setRect(x,y,zombieWidth[zombieNameMap[name]],zombieHeight[zombieNameMap[name]]);
      }
   }
   else
   {
       plant* frontplt=qgraphicsitem_cast<plant*>(coItems[0]);
       bite(frontplt);
       if(status!=STAT_BITE)
       {
           status=STAT_BITE;
           QString zombiePath="images/Zombies/"+name+"/"+name+"attack.gif";
           setGif(zombiePath);
           setRect(x,y,zombieAttackWidth[zombieNameMap[name]],zombieAttackHeight[zombieNameMap[name]]);
       }
   }

}


void zombie::bite(plant* plt)
{
    if(plt->getPumpkin())
         plt->getPumpkin()->hurt(attack);
    else
        plt->hurt(attack);
    if(plt->name=="garlic")
    {
        isVerticalWalking = 1;
        if(row == 0) {
            targetRow = 1;
            targetY = y + grassY[1]-grassY[0];}
        else if(row == 4) {
            targetRow = 3;
            targetY = y + grassY[3]-grassY[4];}
        else {
            targetRow = row + 2*rand()%2 - 1;
            targetY = y + grassY[targetRow] - grassY[row];
        }
        if(targetRow>row) verticalSpeed = 8;
        else verticalSpeed = -8;
        row = -1;//不可选中状态
        cout<<"bite"<<endl;
    }
}



void zombie::hurt(int damage)
{
	health = health - damage;
	if (health <= 0)
		dead();
}

void zombie::dead()
{
    point = point + bonus;
    scene()->removeItem(this);
    delete this;
    return;
}

void zombie::decelerate(int val, int mode)
{
	if (mode == MODE_CHG)
		speed = max(1, speed - val);
	else
		speed = val;
}




