#include "jeu.h"

jeu::jeu()
{
    Aventurier = aventurier({0.0, 0.0});
    Monstres.push_back(monstre({5.0, 5.0}));
    Monstres.push_back(monstre({-4.0, 5.0}));
}


void Jeu::jouer() {
    std::cout << "Bienvenue dans le jeu!" << std::endl;
    std::cout << "Utilisez les touches A, D, W, S, T, Z pour jouer." << std::endl;
    std::cout << "A : Déplacer à gauche, D : Déplacer à droite, W : Déplacer en haut, S : Déplacer en bas" << std::endl;
    std::cout << "T : Attaquer le monstre, Z : Ramasser l'amulette" << std::endl;

    char input;
    while (Aventurier.estVivant()) {
    	
        std::cout << "Entrez une commande : ";
        std::cin >> input;
        handleInput(input); 
        updateGame();
        
    }
    std::cout << "Game Over! Vous avez été vaincu." << std::endl;
}
void Jeu::handleInput(char Choix) {
    switch (Choix) {
        case 'A':
            Aventurier.deplacerVersGauche();
            break;
        case 'D':
            Aventurier.deplacerVersDroite();
            break;
        case 'W':
            Aventurier.deplacerVersHaut();
            break;
        case 'S':
            Aventurier.deplacerVersBas();
            break;
        case 'T':
            Aventurier.attaquerMonstr(Monstres);
            break;
        case 'Z':
            Aventurier.ramasserAmulette();
            break;
        default:
           
            break;
    }
}
