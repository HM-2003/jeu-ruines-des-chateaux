#ifndef MONSTREAVEUGLE_H
#define MONSTREAVEUGLE_H

#include "Monstre.h" 
#include "Mur.h"
#include "aventurier.h"


class MonstreAveugle : public Monstre {
public:
    MonstreAveugle(const geom::point& position, int pointsDeVie, int pointDeForce);
    virtual ~MonstreAveugle(); 
    void deplacer() override;
    void attaquerAventurier(Aventurier& aventurier) override;
    void recevoirDegats(int degats) override;
    bool toucherMur(const geom::Mur& mur) const;
    bool estVaincu() const;

private:
};


#endif // MONSTREAVEUGLE_H
