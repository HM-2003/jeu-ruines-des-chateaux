#include"monstreNormale.h"
MonstreNormale::MonstreNormale(const geom::point& position, int pointsDeVie, int pointDeForce)
    : Monstre(position, pointsDeVie, pointDeForce) {}

bool MonstreNormale::toucherMur(const geom::Mur& mur) const {
    return (position == mur.obtenir_position());
}

void MonstreNormale::attaquerAventurier(aventurier& aventurier) override
{
    aventurier.recevoirDegats(pointDeForce);
}


void MonstreNormale::deplacer(const geom::Mur& mur, const aventurier& aventurier) {
    double distance = position.distance(aventurier.obtenir_position());

    if (distance == 8.0) {
        double dx = aventurier.obtenir_position().x() - position.x();
        double dy = aventurier.obtenir_position().y() - position.y();
        position.move(dx, dy);
    }
    else if (distance <= 2.0) {
        attaquerAventurier();
    }
    else {
        int dx = rand() % 3 - 1;
        int dy = rand() % 3 - 1;
        position.move(dx, dy);

        if (toucherMur(mur)) {
            position.move(-dx, -dy);
        }
    }
}

void MonstreNormale::recevoirDegats(int degats) {
    Monstre::recevoirDegats(degats);
}
bool MonstreNormale::estVaincu() const {
    return Monstre::estVaincu();
}
