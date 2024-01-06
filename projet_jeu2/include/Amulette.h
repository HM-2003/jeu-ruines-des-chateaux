#ifndef AMULETTE_H
#define AMULETTE_H

#include "point.h"

namespace geom {
    class Amulette {
    public:
        Amulette(const point& positionInitiale);
        //Amulette(const Amulette& autre);  // Constructeur de copie

        point getPosition() const;
        char getSymbole() const;

    private:
        point position;
    };
}

#endif // AMULETTE_H

