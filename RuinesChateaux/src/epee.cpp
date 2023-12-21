#include "epee.h"

Epee::Epee(int solidite):Equipement(solidite)
{
    //ctor
}


int Epee::attaquer()
{
    if(utiliser())
        return soliditeMax;
    else
        return 0;
}

