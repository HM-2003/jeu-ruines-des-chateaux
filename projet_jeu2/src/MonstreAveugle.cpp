#include "MonstreAveugle.h"

namespace geom {
    MonstreAveugle::MonstreAveugle(const point& positionInitiale, int pv, int force)
        : Monstre(positionInitiale, pv, force) {}

   void MonstreAveugle::deplacer() {
    // G�n�rer une direction al�atoire
    int dx = rand() % 3 - 1;
    int dy = rand() % 3 - 1; 

    position.move(dx, dy);

    
}

    char MonstreAveugle::getSymbole() const {
        return 'V'; 
    }
}

