#include "Monstre.h"
#include "Aventurier.h"
namespace geom {
    Aventurier::Aventurier(const point& positionInitiale, int pv, int force): position(positionInitiale), pointsDeVie(pv), pointsDeForce(force) {}
    
    
      Aventurier::Aventurier(const Aventurier& autre): position(autre.position), pointsDeVie(autre.pointsDeVie), pointsDeForce(autre.pointsDeForce) {}
      


      void Aventurier::deplacer(char direction) {
   double dx = 0, dy = 0;
            switch (direction) {
                case 'w': dy = -1; break;
                case 's': dy = 1; break;
                case 'a': dx = -1; break;
                case 'd': dx = 1; break;
            }

            point newPosition = position;
            newPosition.move(dx, dy);
}

    void Aventurier::subirDegats(int degats) {
    	if(armure) {
            
            armure->utiliser();
        }
        pointsDeVie -= degats;
        if (pointsDeVie < 0) {
            pointsDeVie = 0;
        }
    }
     void Aventurier::attaquer(Monstre& monstre) {
    double distance = position.distance(monstre.getPosition());
    if (distance <= 1.0) { 
        int degats = pointsDeForce;
        if (epee) {
            degats += epee->getSolidite();
            epee->utiliser(); 
        }
        monstre.subirDegats(degats);

        std::cout << "L'aventurier a attaqué le monstre." << std::endl;
    } else {
        std::cout << "Le monstre est trop loin pour être attaqué." << std::endl;
    }
}

    
    
     void Aventurier::equiperEpee(Epee* nouvelleEpee) {
        epee = nouvelleEpee;
    }

    void Aventurier::enleverEpee() {
        epee = nullptr;
    }

    void Aventurier::equiperArmure(Armure* nouvelleArmure) {
        armure = nouvelleArmure;
    }

    void Aventurier::enleverArmure() {
        armure = nullptr;
    }
    

    point Aventurier::getPosition() const {
        return position;
    }

    int Aventurier::getPV() const {
        return pointsDeVie;
    }

    int Aventurier::getForce() const {
        return pointsDeForce;
    }

    char Aventurier::getSymbole() const {
        return 'A';
    }
}

