/*#include "Jeu.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

namespace geom {

Jeu::Jeu(int largeurTerrain, int hauteurTerrain)
    : terrain(largeurTerrain, hauteurTerrain), enCours(false) {
   aventurier = std::make_unique<Aventurier>(point(0, 0), 100, 10); // Exemple

    // Ajouter des monstres
    MonstreVoyant monstre1(point(3, 3), 50, 5);
    MonstreAveugle monstre2(point(5, 5), 50, 5);
    terrain.ajouterMonstre(monstre1);
    terrain.ajouterMonstre(monstre2);

    // Ajouter une amulette
    Amulette amulette(point(9, 9));
    terrain.placerAmulette(&amulette);

}

void Jeu::demarrer() {
    afficherMenu();
    while (jeuEnCours()) {
        traiterInput();
        miseAJour();
        afficherTerrain();
    }
}

void Jeu::afficherMenu() {
    char choix;
    std::cout << "Bienvenue dans le jeu d'aventure!" << std::endl;
    std::cout << "Appuyez sur 'Y' pour commencer ou 'Q' pour quitter: ";
    std::cin >> choix;

    if (choix == 'Y' || choix == 'y') {
        enCours = true;
    } else {
        enCours = false;
    }
}

void Jeu::traiterInput() {
    char commande;
    std::cout << "Entrez une commande ('a' gauche, 'd' droite, 'w' haut, 's' bas, 'F' attaquer): ";
    std::cin >> commande;

    switch (commande) {
        case 'a':
            deplacerAventurier();
            break;
        case 'd':
            deplacerAventurier();
            break;
        case 'w':
            deplacerAventurier();
            break;
        case 's':
            deplacerAventurier();
            break;
        case 'F':
            // aventurier->attaquer(); // implémentez la logique d'attaque
            break;
        default:
            std::cout << "Commande inconnue!" << std::endl;
    }
}

void Jeu::miseAJour() {
    deplacerMonstres();
    verifierVictoire();
}

bool Jeu::jeuEnCours() const {
    return enCours;
}

void Jeu::deplacerAventurier() {
    // Implémentez la logique de déplacement de l'aventurier ici
}

void Jeu::deplacerMonstres() {
    for (auto& monstre : monstres) {
        // monstre->deplacer();
    }
}

void Jeu::verifierVictoire() {
    if () {
        std::cout << "Vous avez gagné!" << std::endl;
        enCours = false;
    }
}

void Jeu::afficherTerrain() {
    terrain.afficher();
}

} // namespace geom

*/
