#include "aventurier.h"
#include "monstre.h"

aventurier::aventurier(const point& position, int pointDeVie, int pointDeForce)
    : Position(position), PointDeVie(pointDeVie), PointDeForce(pointDeForce), PossedeAmulette(false) {}



void aventurier::deeplacerVersGauche() {
	
    Position.move(-1.0, 0.0);

}


void aventurier::deplacerVersDroite() {
	
    Position.move(1.0, 0.0);
}


void aventurier::deplacerVersHaut() {
	
    Position.move(0.0, 1.0);
}


void aventurier::deplacerVersBas() {
	
    Position.move(0.0, -1.0);
}


void aventurier::attaquerMonstr(std::vector<monstre>& Monstres) {
    bool tousVaincus = true;

    for (monstre& Monstre : Monstres) {
    	
        if (Position.distance(Monstre.getPosition()) < 2.0 && !Monstre.estVaincu()) {
        	
            Monstre.recevoirDegats(PointDeForce);
            
            if (!Monstre.estVaincu()) {
            	
                tousVaincus = false;
            }
        }
    }

    if (tousVaincus) {
    	
       ramasserAmulette();
       
        std::cout << "Aventurier a gagné une amulette!" << std::endl;
    }
}


void aventurier::ramasserAmulette() {
	
    PossedeAmulette = true;
}

voidaventurier::recevoirDegats(int degats) {
    PointDeVie -= degats;   
    if (!estVivant()) {
    	
        std::cout << "Aventurier est vaincu!" << std::endl;
          }
		  }
          
bool aventurier::estVivant() const {
	
    return PointDeVie > 0;
}