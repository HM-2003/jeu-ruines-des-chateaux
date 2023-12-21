#include "equipement.h"
#include<iostream>
#include<cstdlib>

Equipement::Equipement(int solidite):soliditeActuelle{solidite},soliditeMax{solidite}
{}




bool Equipement::utiliser()
{
    if(soliditeActuelle>0)
    {
        soliditeActuelle--;
       return true ;
    }
    else
    {
       std::cout<<"equipement cassé" <<std::endl;
    return false;
    }
}

/*void equipement::reparer(int pieces)
{

}
*/
