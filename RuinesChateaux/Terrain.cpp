#include "Terrain.h"
#include <iostream>

namespace geom {
    Terrain::Terrain(int l, int h) : largeur(l), hauteur(h) {}

    void Terrain::placerMur(const Mur& mur) {
        murs.push_back(mur);
    }
    
 void Terrain::ajouterMonstre(Monstre* monstre) {
    monstres.push_back(std::unique_ptr<Monstre>(monstre));
}

    void Terrain::placerAventurier(Aventurier* a) {
        aventurier.reset(a);  
    }

    void Terrain::placerAmulette(Amulette* a) {
        amulette = a;
   }

    void Terrain::afficher() const {
        for (int y = 0; y < hauteur; ++y) {
            for (int x = 0; x < largeur; ++x) {
                point pos(x, y);
                if (aventurier && aventurier->getPosition() == pos) {
                    std::cout << aventurier->getSymbole();
                } else if (amulette && amulette->getPosition() == pos) {
                    std::cout << amulette->getSymbole();
                } else {
                    bool affiche = false;
                    for (const auto& mur : murs) {
                        if (mur.getPosition() == pos) {
                            std::cout << mur.getSymbole();
                            affiche = true;
                            break;
                        }
                    }
                    if (!affiche) {
                       for (const auto& monstre : monstres) {
                         if (monstre->getPosition() == pos) { 
                         std::cout << monstre->getSymbole();
                         affiche = true;
                          break;
        }
    }
                    }
                    if (!affiche) std::cout << '.'; // Espace vide
                }
            }
            std::cout << std::endl;
        }
    }
}
 
