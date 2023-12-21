#ifndef MUR_H
#define MUR_H
 // Inclure le fichier d'en-tête de la classe point
#include "point.h" 
#include <memory>

namespace geom {

class Mur {
private:
    std::unique_ptr<point> position; 

public:
    // Constructeur de la class Mur
    Mur(double x, double y);

    // Destructeur 
    ~Mur();

    // Méthode pour obtenir la position du mur
    const point& obtenir_position() const;
};

} // namespace geom

#endif // MUR_H
