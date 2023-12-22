#ifndef MONSTRE_H
#define MONSTRE_H

#include "point.h"
#include "aventurier.h"
#include"Mur.h"
class Monstre {
public:
    Monstre(const geom::point& position, int pointsDeVie, int pointDeForce, int pointsDurabilite);
    virtual ~Monstre();
    virtual void attaquerAventurier(int pointsDeAventurier) const = 0;
    virtual void deplacer(const geom::Mur& mur, const aventurier& aventurier) const = 0;
    virtual void recevoirDegats(int degats) const = 0;
    bool estVaincu() const;

protected:
    int pointsDeVie;
    int pointDeForce;
    geom::point position;
    int pointsDurabilite;
};

#endif // MONSTRE_H
