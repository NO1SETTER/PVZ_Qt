#include"SunFLower.h"

void SunFLower::advance(int phase)
{
if(!phase) return;
if(sunCounter<100) sunCounter = sunCounter + 1;
else
{   sunCounter = 0;
    sun =sun + 25;
}


}
