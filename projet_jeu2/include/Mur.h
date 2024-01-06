#ifndef MUR__H
#define MUR__H

#include "point.h"

namespace geom {
    class Mur {
    public:
        Mur(const point& position);

        point getPosition() const;
        char getSymbole() const; // Pour l'affichage dans la console

    private:
        point position;
    };
}

#endif // MUR__H

