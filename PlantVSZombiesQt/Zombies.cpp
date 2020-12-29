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
    headGif = NULL;
    deadBodyGif = NULL;
    bombGif = NULL;
	status = STAT_MOV;
    isVerticalWalking = 0;
    deadCounter = 0;
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
    deadCounter = 0;
    QString zombiePath="images/Zombies/"+_name+"/"+_name+".gif";
    setGif(zombiePath);
    if(name == "polevaultingzombie") headGif = new QMovie("images/Zombies/PoleVaultingZombie/PoleVaultingZombieHead.gif");
    else headGif = new QMovie("images/Zombies/NormalZombie/NormalZombieHead.gif");

    if(name == "polevaultingzombie") deadBodyGif = new QMovie("images/Zombies/PoleVaultingZombie/PoleVaultingZombieDie.gif");
    else if(name== "flagzombie") deadBodyGif = new QMovie("images/Zombies/FlagZombie/FlagZombieLostHead.gif");
    else deadBodyGif = new QMovie("images/Zombies/NormalZombie/NormalZombieLostHead.gif");

    bombGif = new QMovie("images/Zombies/BoomDie.gif");
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
    if(status == STAT_BOMB_DEAD)
    {
        if(deadCounter<15)
        {
            painter->drawPixmap(QRect(x-200,y-80,zombieBombWidth[zombieNameMap[name]],zombieBombHeight[zombieNameMap[name]]),bombGif->currentPixmap());
            deadCounter = deadCounter + 1;
        }
        else
        {
            scene()->removeItem(this);
            delete this;
        }
        return;
    }
    else if(status == STAT_HIT_DEAD)
    {
        if(deadCounter<15)
        {
            painter->drawPixmap(QRect(x-40,y-20,zombieHeadWidth[zombieNameMap[name]],zombieHeadHeight[zombieNameMap[name]]),headGif->currentPixmap());
            painter->drawPixmap(QRect(x-40,y-20,zombieBodyWidth[zombieNameMap[name]],zombieBodyHeight[zombieNameMap[name]]),deadBodyGif->currentPixmap());
            deadCounter = deadCounter + 1;
        }
        else
        {
            scene()->removeItem(this);
            delete this;
        }
        return;
    }
    else painter->drawPixmap(QRect(x,y,width,height),zombieGif->currentPixmap());
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
   if(coItems.isEmpty()||status == STAT_HIT_DEAD||status == STAT_BOMB_DEAD)//死亡之后就不需要考虑碰撞了
   {
      if(status == STAT_BOMB_DEAD) return;//炸死的原地不动
      x = x - speed;
      if(status!=STAT_MOV&&status!=STAT_HIT_DEAD&&status!=STAT_BOMB_DEAD)
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
    }
}



void zombie::hurt(int damage)
{
	health = health - damage;
	if (health <= 0)
    {
        if(damage == 80) dead(STAT_BOMB_DEAD);
        else dead(STAT_HIT_DEAD);
    }
}

void zombie::dead(int _status) //调整advance 让它不能修改dead状态
{
    point = point + bonus;
    status = _status;
    if(status == STAT_BOMB_DEAD) bombGif->start();
    else
    {
        headGif->start();
        deadBodyGif->start();
    }
    zombieGif->stop();
}

void zombie::decelerate(int val, int mode)
{
	if (mode == MODE_CHG)
		speed = max(1, speed - val);
	else
		speed = val;
}




