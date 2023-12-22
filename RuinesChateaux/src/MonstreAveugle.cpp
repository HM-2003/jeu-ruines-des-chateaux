#include "monstreAveugle.h"

MonstreAveugle::MonstreAveugle(const geom::point& position, int pointsDeVie, int pointDeForce)
    : Monstre(position, pointsDeVie, pointDeForce) {}

void MonstreAveugle::deplacer(const geom::Mur& mur, const Aventurier& aventurier) { 
    int dx = rand() % 3 - 1;
    int dy = rand() % 3 - 1;
    position.move(dx, dy);

    if (toucherMur(mur)) {
        // Le monstre change de direction 
        position.move(-dx, -dy);
    }
}

void MonstreNormale::recevoirDegats(int degats) {
    Monstre::recevoirDegats(degats);  
}

bool MonstreAveugle::estVaincu() const {
    return Monstre::estVaincu();
}

void MonstreAveugle::attaquerAventurier(Aventurier& aventurier) {
    aventurier.recevoirDegats(pointDeForce * 2);
}