#include"SunFLower.h"
#include"Sun.h"
void SunFLower::advance(int phase)
{
if(!phase) return;
if(sunCounter<100) sunCounter = sunCounter + 1;
else
{   sunCounter = 0;
    Sun* s = new Sun(rand()%(width/2)+x,rand()%(height/2)+y);
    scene()->addItem(s);
}


}
