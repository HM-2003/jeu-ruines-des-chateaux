#ifndef AVENTURIER_H
#define AVENTURIER_H
#include"Monstre.h"
#include "point.h"
#include "Epee.h"
#include "Armure.h"

namespace geom {
	 class Monstre;
    class Aventurier {
    public:
        Aventurier(const point& positionInitiale, int pv, int force);
         Aventurier(const Aventurier& autre);
       void deplacer(char direction);
      
        void subirDegats(int degats);
        void attaquer(Monstre& monstre);
        
        void equiperEpee(Epee* nouvelleEpee);
        void enleverEpee();
        void equiperArmure(Armure* nouvelleArmure);
        void enleverArmure();
        
        point getPosition() const;
        int getPV() const;
        int getForce() const;
        char getSymbole() const;

    private:
        point d_position;
        int d_pointsDeVie;
        int d_pointsDeForce;
        Epee* d_epee;
        Armure* d_armure;
    };
}

#endif // AVENTURIER_H

