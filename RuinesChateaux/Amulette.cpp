#include "Amulette.h"
namespace geom {
    Amulette::Amulette(const point& positionInitiale) : position(positionInitiale) {}

   // Amulette::Amulette(const Amulette& autre) : position(autre.position) {}  // Constructeur de copie

    point Amulette::getPosition() const {
        return position;
    }

    char Amulette::getSymbole() const {
        return '@';  
    }
}

