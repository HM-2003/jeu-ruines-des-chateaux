#include "Equipement.h"

Equipement::Equipement(int soliditeInitiale) : solidite(soliditeInitiale) {}

void Equipement::deteriorer() {
    if (solidite > 0) {
        solidite--;
    }
}

void Equipement::reparer(int nbPieces) {
    solidite += nbPieces;
}

int Equipement::getSolidite() const {
    return solidite;
}

Equipement::~Equipement() {
   
}

