#include "Monstre.h"
#include "Aventurier.h"
namespace geom {
    Aventurier::Aventurier(const point& positionInitiale, int pv, int force): d_position(positionInitiale), d_pointsDeVie(pv), d_pointsDeForce(force) {}
    
    
      Aventurier::Aventurier(const Aventurier& autre): d_position(autre.d_position), d_pointsDeVie(autre.d_pointsDeVie), d_pointsDeForce(autre.d_pointsDeForce) {}
      


 void Aventurier::deplacer(char direction) {
    double dx = 0, dy = 0;
    switch (direction) {
        case 'w': dy = -1; break;
        case 's': dy = 1; break;
        case 'a': dx = -1; break;
        case 'd': dx = 1; break;
    }

    d_position.move(dx, dy);
    std::cout << "Position mise à jour : " << d_position.x() << ", " << d_position.y() << std::endl; // Message de débogage
}

    void Aventurier::subirDegats(int degats) {
    	if(d_armure) {
            
            d_armure->utiliser();
        }
        d_pointsDeVie -= degats;
        if (d_pointsDeVie < 0) {
            d_pointsDeVie = 0;
        }
    }
     void Aventurier::attaquer(Monstre& monstre) {
    double distance = d_position.distance(monstre.getPosition());
    if (distance <= 1.0) { 
        int degats = d_pointsDeForce;
        if (d_epee) {
            degats += d_epee->getSolidite();
            d_epee->utiliser(); 
        }
        monstre.subirDegats(degats);

        std::cout << "L'aventurier a attaqué le monstre." << std::endl;
    } else {
        std::cout << "Le monstre est trop loin pour être attaqué." << std::endl;
    }
}

    
    
     void Aventurier::equiperEpee(Epee* nouvelleEpee) {
        d_epee = nouvelleEpee;
    }

    void Aventurier::enleverEpee() {
        d_epee = nullptr;
    }

    void Aventurier::equiperArmure(Armure* nouvelleArmure) {
        d_armure = nouvelleArmure;
    }

    void Aventurier::enleverArmure() {
        d_armure = nullptr;
    }
    

    point Aventurier::getPosition() const {
        return d_position;
    }

    int Aventurier::getPV() const {
        return d_pointsDeVie;
    }

    int Aventurier::getForce() const {
        return d_pointsDeForce;
    }

    char Aventurier::getSymbole() const {
        return 'A';
    }
}

