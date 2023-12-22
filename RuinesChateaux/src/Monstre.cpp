#include "Monstre.h"

Monstre::Monstre(const geom::point& position, int pointsDeVie, int pointDeForce, int pointsDurabilite)
    : position(position), pointsDeVie(pointsDeVie), pointDeForce(pointDeForce), pointsDurabilite(pointsDurabilite) {}

Monstre::~Monstre() {}

bool Monstre::estVaincu() const {
    return pointsDeVie <= 0;
}
