#ifndef MONSTREAVEUGLE_H
#define MONSTREAVEUGLE_H

#include "Monstre.h"
#include "Mur.h"
#include "aventurier.h"


class MonstreAveugle : public Monstre {
public:
    MonstreAveugle(const geom::point& position, int pointsDeVie, int pointDeForce,int pointDurabilite);
    virtual ~MonstreAveugle();
    void deplacer(const geom::Mur& mur, const aventurier& aventurier)override;
    void attaquerAventurier(int pointsDeAventurier) override;
    void recevoirDegats(int degats) override;
    bool toucherMur(const geom::Mur& mur) const;
    bool estVaincu() const;

private:
};


#endif // MONSTREAVEUGLE_H
