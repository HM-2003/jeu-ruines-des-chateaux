#ifndef TERRAIN_H
#define TERRAIN_H

#include "point.h"
#include "Mur.h"
#include "Monstre.h"
#include "Aventurier.h"
#include "Amulette.h"
#include <vector>
#include <memory>

namespace geom {
    class Terrain {
    public:
        Terrain(int largeur, int hauteur);

        void placerMur(const Mur& mur);
      void ajouterMonstre(Monstre* monstre);
       void placerAventurier(Aventurier* a);
        void placerAmulette(Amulette* a);

        bool estMur(const point& position) const;
        bool estAmulette(const point& position) const;
        bool estMonstre(const point& position) const;
        bool estAventurier(const point& position) const;
        bool estPositionLibre(const point& pos) const;
        void afficher() const;

    private:
        int largeur, hauteur;
        std::vector<Mur> murs;
          std::vector<std::unique_ptr<Monstre>> monstres;
        std::unique_ptr<Aventurier> aventurier;
        Amulette* amulette;
    };
}

#endif // TERRAIN_H

