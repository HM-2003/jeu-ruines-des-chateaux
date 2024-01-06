#include "Monstre.h"
  namespace geom {
    
    Monstre::Monstre(const point& positionInitiale, int pv, int force): position(positionInitiale), pointsDeVie(pv), pointsDeForce(force) {}

    void Monstre::subirDegats(int degats) {
        pointsDeVie -= degats;
        if (pointsDeVie < 0) pointsDeVie = 0;
    }
    
     void Monstre::attaquer(Aventurier& aventurier) {
    double distance = position.distance(aventurier.getPosition());
    if (distance <= 1.0) { // Si l'aventurier est � une case de distance
        int degats = pointsDeForce; 
        aventurier.subirDegats(degats);

        std::cout << "Le monstre a attaqu� l'aventurier." << std::endl;
    } else {
        std::cout << "L'aventurier est trop loin pour �tre attaqu�." << std::endl;
    }
     }
    point Monstre::getPosition() const {
        return position;
    }

    int Monstre::getPV() const {
        return pointsDeVie;
    }

    int Monstre::getForce() const {
        return pointsDeForce;
    }
}
