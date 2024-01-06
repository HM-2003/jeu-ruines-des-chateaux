#include "MonstreVoyant.h"

namespace geom {
    MonstreVoyant::MonstreVoyant(const point& positionInitiale, int pv, int force)
        : Monstre(positionInitiale, pv, force) {}

    void MonstreVoyant::deplacer(const point& positionAventurier) {
    if (position.distance(positionAventurier) <= 5.0) {
       
        int dx = (positionAventurier.x() > position.x()) ? 1 : (positionAventurier.x() < position.x()) ? -1 : 0;
        int dy = (positionAventurier.y() > position.y()) ? 1 : (positionAventurier.y() < position.y()) ? -1 : 0;

     
        position.move(dx, dy);

        
    }
}

    char MonstreVoyant::getSymbole() const {
        return 'M'; // Symbole représentant le Monstre Voyant
    }
}

