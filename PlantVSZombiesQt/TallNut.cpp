#include"TallNut.h"



void TallNut::advance(int phase)
{
    if(!phase) return;
    if(health<=300&&health>150&&status!=STAT2)
    {
        status=STAT2;
        setGif("images/Plants/TallNut/TallnutCracked1.gif");
    }
    else if(health<=150&&status!=STAT3)
    {
        status=STAT3;
        setGif("images/Plants/TallNut/TallnutCracked2.gif");
    }
}
