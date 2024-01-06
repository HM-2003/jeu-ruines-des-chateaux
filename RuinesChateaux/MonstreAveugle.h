#ifndef MONSTREAVEUGLE_H
#define MONSTREAVEUGLE_H

#include "Monstre.h"

namespace geom {
    class MonstreAveugle : public Monstre {
    public:
        MonstreAveugle(const point& positionInitiale, int pv, int force);
        char getSymbole() const ;
        void deplacer() ; 
        
    };
}

#endif // MONSTREAVEUGLE_H

