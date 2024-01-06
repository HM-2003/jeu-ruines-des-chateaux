
#include "Mur.h"

namespace geom {
    Mur::Mur(const point& positionInitiale) : position(positionInitiale) {}

    point Mur::getPosition() const {
        return position;
    }

    char Mur::getSymbole() const {
        return '#'; 
    }
}

