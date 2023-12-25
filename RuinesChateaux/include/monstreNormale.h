#ifndef MONSTRENORMALE_H
#define MONSTRENORMALE_H

#include "Monstre.h"
#include "point.h"
#include "Mur.h"

class MonstreNormale : public Monstre {
public:
    MonstreNormale(const geom::point& position, int pointsDeVie, int pointDeForce,int pointDurabilite);
    void deplacer(const geom::Mur& mur, const aventurier& aventurier) override;
    void attaquerAventurier(int pointsDeAventurier) override;
    void recevoirDegats(int degats) override;
    bool toucherMur(const geom::Mur& mur) const;
    bool estVaincu() const;

private:
};

#endif // MONSTRENORMALE_H
