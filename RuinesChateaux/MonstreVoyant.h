#ifndef MONSTREVOYANT_H
#define MONSTREVOYANT_H

#include "Monstre.h"

namespace geom {
    class MonstreVoyant : public Monstre {
    public:
        MonstreVoyant(const point& positionInitiale, int pv, int force);
        char getSymbole() const override;
        void deplacer(const point& positionAventurier); 
    };
}

#endif // MONSTREVOYANT_H

