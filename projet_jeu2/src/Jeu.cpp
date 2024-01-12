#include "Jeu.h"
#include <iostream>
#include <cstdlib>
#include <ctime>


namespace geom {
    Jeu::Jeu() : terrain(40, 20), aventurier(nullptr), amulette(nullptr) {
  
    }

    Jeu::~Jeu() {
        delete aventurier;
        for (auto monstre : monstres) {
            delete monstre;
        }
        delete amulette;
    }

    void Jeu::initialiserJeu() {
        for (int i = 0; i < 40; ++i) {
        terrain.placerMur(geom::Mur(geom::point(i, 0)));  
        terrain.placerMur(geom::Mur(geom::point(i, 19))); 
    }
    for (int j = 1; j < 19; ++j) {
        terrain.placerMur(geom::Mur(geom::point(0, j)));  
        terrain.placerMur(geom::Mur(geom::point(39, j)));
    }
for (int i = 20; i < 40; ++i) {
    terrain.placerMur(geom::Mur(geom::point(i, 14)));
     terrain.placerMur(geom::Mur(geom::point(i, 8)));
}
for (int y = 2; y < 5; ++y) {
    terrain.placerMur(geom::Mur(geom::point(26, y)));
	  
}

for (int y = 17; y < 20; ++y) { 
    terrain.placerMur(geom::Mur(geom::point(28, y)));
}
    for (int i = 1; i < 20; ++i) {
        terrain.placerMur(geom::Mur(geom::point(i, 5)));
        terrain.placerMur(geom::Mur(geom::point(i, 10)));
          terrain.placerMur(geom::Mur(geom::point(i, 17)));
        if (i > 20 && i < 30) {
            terrain.placerMur(geom::Mur(geom::point(i, 15)));
           
        }
    }

   
    geom::Aventurier* aventurier = new geom::Aventurier(geom::point(1, 1), 100, 10);
    terrain.placerAventurier(aventurier);

   
    std::vector<geom::Monstre*> monstres;
    monstres.push_back(new geom::MonstreVoyant(geom::point(10, 3), 50, 5));
    monstres.push_back(new geom::MonstreAveugle(geom::point(25, 10), 40, 4));
    monstres.push_back(new geom::MonstreVoyant(geom::point(35, 15), 60, 6));
     monstres.push_back(new geom::MonstreAveugle(geom::point(34, 4), 40, 4));
     monstres.push_back(new geom::MonstreAveugle(geom::point(4, 18), 40, 4));
    for (auto monstre : monstres) {
        terrain.ajouterMonstre(monstre);
    }

    geom::Amulette* amulette = new geom::Amulette(geom::point(38, 18));
    terrain.placerAmulette(amulette);

   
    }

    void Jeu::lancerJeu() {
        initialiserJeu();
        tourDeJeu();
    }

  void Jeu::tourDeJeu() {
    bool jeuEnCours = true;
    while (jeuEnCours) {
        terrain.afficher(); 

        deplacerAventurier(); 
        deplacerMonstres();

        for (size_t i = 0; i < monstres.size(); ++i) {
            if (aventurier->getPosition() == monstres[i]->getPosition()) {
                aventurier->attaquer(*monstres[i]);
                if (monstres[i]->getPV() <= 0) {
                    delete monstres[i];
                    monstres.erase(monstres.begin() + i);
                    --i; 
                    continue; 
                }
                monstres[i]->attaquer(*aventurier);
                if (aventurier->getPV() <= 0) {
                    std::cout << "Vous avez été vaincu par le monstre." << std::endl;
                    jeuEnCours = false;
                    break;
                }
            }
        }

        if (aventurierAGagne()) {
            std::cout << "Vous avez trouvé l'amulette! Vous avez gagné!" << std::endl;
            jeuEnCours = false;
        }
    }
}

void Jeu::deplacerAventurier() {
    char direction;
    std::cout << "Entrez une direction (w: haut, a: gauche, s: bas, d: droite): ";
    std::cin >> direction;

    point nouvellePosition = aventurier->getPosition(); // Déclaration de nouvellePosition

    switch (direction) {
        case 'w': 
            nouvellePosition.move(0, -1);
            break;
        case 'a': 
            nouvellePosition.move(-1, 0);
            break;
        case 's': 
            nouvellePosition.move(0, 1);
            break;
        case 'd': 
            nouvellePosition.move(1, 0);
            break;
        default:
            std::cout << "Direction non valide. Veuillez réessayer." << std::endl;
            return;
    }

    if (terrain.estPositionLibre(nouvellePosition)) {
        aventurier->deplacer(direction);
        terrain.afficher();
    } else {
        std::cout << "Déplacement impossible : position occupée ou hors limites." << std::endl;
    }
}


void Jeu::deplacerMonstres() {
    for (auto monstre : monstres) {
        if (auto mv = dynamic_cast<MonstreVoyant*>(monstre)) {
            
            mv->deplacer(aventurier->getPosition());
        } else if (auto ma = dynamic_cast<MonstreAveugle*>(monstre)) {
            
            int dx = rand() % 3 - 1; 
            int dy = rand() % 3 - 1; 

            point nouvellePosition = ma->getPosition();
            nouvellePosition.move(dx, dy);

            if (terrain.estPositionLibre(nouvellePosition)) {
                ma->deplacer();
            }
        }
    }
}
  bool Jeu::aventurierAGagne() {
 
    if (aventurier->getPosition() == amulette->getPosition()) {
        return true; 
    }
    return false;
}

}


