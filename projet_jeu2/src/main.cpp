#include "Terrain.h"
#include "Mur.h"
#include "Aventurier.h"
#include "MonstreVoyant.h"
#include "Amulette.h"
#include <iostream>
#include <vector>
#include <thread>  // Pour std::this_thread
#include <chrono>  
int main() {
    geom::Terrain terrain(10, 10); // Assurez-vous que le constructeur de Terrain prend ces paramètres

    // Ajout de murs
    terrain.placerMur(geom::Mur(geom::point(1, 0)));
    terrain.placerMur(geom::Mur(geom::point(1, 1)));
    terrain.placerMur(geom::Mur(geom::point(2, 2)));

    // Création et placement de l'aventurier
    geom::Aventurier aventurier(geom::point(0, 0), 100, 10); 
    terrain.placerAventurier(&aventurier);

    // Ajout d'un monstre
    std::vector<geom::MonstreVoyant> monstres;
    monstres.push_back(geom::MonstreVoyant(geom::point(3, 3), 50, 5));
    // Ajoutez plus de monstres si nécessaire

    // Ajout d'une amulette
    geom::Amulette amulette(geom::point(9, 9)); 
    terrain.placerAmulette(&amulette);

    terrain.afficher();

    terrain.afficher();

    for (int tour = 0; tour < 10; ++tour) {
        // Nettoyer l'écran à chaque tour pour donner l'illusion d'un terrain unique
        #ifdef _WIN32
        system("cls");
        #else
        system("clear");
        #endif

        std::cout << "Tour " << tour + 1 << std::endl;

        // Obtenir la position de l'aventurier
        geom::point positionAventurier = aventurier.getPosition();

        // Mettre à jour la position de chaque monstre
        for (geom::MonstreVoyant& monstre : monstres) {
            monstre.deplacer(positionAventurier);
            // Si nécessaire, mettre à jour le terrain avec la nouvelle position du monstre
        }

        // Réafficher le terrain avec les positions mises à jour
        terrain.afficher();

        // Ajouter un délai pour permettre de visualiser les déplacements
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}

