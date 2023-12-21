#include "Mur.h"

namespace geom {

Mur::Mur(double x, double y) : position(std::make_unique<point>(x, y)) {
    // Initialisation du mur
}

Mur::~Mur() {
    // Nettoyage du mur (si nécessaire)
}

const point & Mur::obtenir_position() const {
    return *position;
}

} // namespace geom
