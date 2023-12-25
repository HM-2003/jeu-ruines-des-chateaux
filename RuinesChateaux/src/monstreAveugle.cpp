#include "monstreAveugle.h"
#include"aventurier.h"

MonstreAveugle::MonstreAveugle(const geom::point& position, int pointsDeVie, int pointDeForce,int pointDurabilite)
    : Monstre{position, pointsDeVie, pointDeForce,pointDurabilite} {}

void MonstreAveugle::deplacer(const geom::Mur& mur, const aventurier& aventurier) {
    int dx = rand() % 3 - 1;
    int dy = rand() % 3 - 1;
    position.move(dx, dy);

    if (toucherMur(mur)) {
        // Le monstre change de direction
        position.move(-dx, -dy);
    }
}

void MonstreAveugle::recevoirDegats(int degats){
    Monstre::recevoirDegats(degats);
}

bool MonstreAveugle::estVaincu() const {
    return Monstre::estVaincu();
}

void MonstreAveugle::attaquerAventurier(int pointsDeAventurier) {

    aventurier.recevoirDegats(pointDeForce * 2);
}
