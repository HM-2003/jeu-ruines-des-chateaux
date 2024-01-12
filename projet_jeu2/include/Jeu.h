#ifndef JEU_H
#define JEU_H

#include "Terrain.h"
#include "Aventurier.h"
#include "MonstreVoyant.h"
#include "MonstreAveugle.h"
#include "Mur.h"
#include "Amulette.h"
#include "point.h"
#include <iostream>
#include <vector>

namespace geom {
    class Jeu {
    public:
        Jeu();
        ~Jeu();

        void lancerJeu();

    private:
        Terrain terrain;
        Aventurier* aventurier;
        std::vector<Monstre*> monstres;
        Amulette* amulette;

        void initialiserJeu();
        void tourDeJeu();
        void  deplacerAventurier();
        void deplacerMonstres();
        bool aventurierAGagne();
        void nettoyerRessources();
    };
}

#endif // JEU_H

