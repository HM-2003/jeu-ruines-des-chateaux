#ifndef MONSTRE__H
#define MONSTRE__H
#include "Monstre.h"
#include "Aventurier.h"
#include <iostream>

namespace geom {
	    class  Aventurier;

    class Monstre {
    public:
        Monstre(const point& positionInitiale, int pv, int force);

      void attaquer(Aventurier& aventurier);
        void subirDegats(int degats);
        virtual char getSymbole() const = 0;
        point getPosition() const;
        int getPV() const;
        int getForce() const;

    protected:
        point position;
        int pointsDeVie;
        int pointsDeForce;
    };}

#endif
