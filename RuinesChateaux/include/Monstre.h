#ifndef MONSTRE_H
#define MONSTRE_H

#include "point.h"
//#include "aventurier.h"
#include"Mur.h"
class aventurier;
class Monstre {
public:
    Monstre(const geom::point& position, int pointsDeVie, int pointDeForce, int pointsDurabilite);
    virtual ~Monstre();
    virtual void attaquerAventurier(int pointsDeAventurier) = 0;
    virtual void deplacer(const geom::Mur& mur, const aventurier& aventurier) = 0;
    virtual void recevoirDegats(int degats) = 0;
    bool estVaincu() const;

protected:
    int pointsDeVie;
    int pointDeForce;
    geom::point position;
    int pointsDurabilite;
};

#endif // MONSTRE_H
