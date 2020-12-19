#include"WallNut.h"


void WallNut::advance(int phase)
{
    if(!phase) return;
    if(health<=200&&health>100&&status!=STAT2)
    {
        status=STAT2;
        setGif("images/Plants/WallNut/Wallnut_Cracked1.gif");
    }
    else if(health<=100&&status!=STAT3)
    {
        status=STAT3;
        setGif("images/Plants/WallNut/Wallnut_Cracked2.gif");
    }
}
