#include "armure.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Armure::Armure(int solidite):Equipement(solidite)
{
    //ctor
}



 void Armure::recoisAttaque(int pointdeforce)
 {
     int pointAbsorbes = pointdeforce * 3 / 4;

     int pointAbsorbeparArmure = std::min(pointAbsorbes,soliditeActuelle);

     soliditeActuelle -= pointAbsorbeparArmure;

     int pointAbsorbeparAventurier = pointdeforce - pointAbsorbeparArmure;

     std::cout<<"armure absorbe"<<pointAbsorbeparArmure<<"points de force"<<std::endl;

     std::cout<<"aventurier absorbe"<<pointAbsorbeparAventurier<<"points de force"<<std::endl;
 }
