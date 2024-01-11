
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Monstre.h"

using geom::point;

TEST_SUITE("Tests pour la classe Monstre") {
	
    TEST_CASE("Test du constructeur de Monstre avec de petits nombres") {
    point positionInitiale(1, 1);
    int pvInitiaux = 10;
    int forceInitiale = 5;
    
    Monstre monstre(positionInitiale, pvInitiaux, forceInitiale);
    
    REQUIRE_EQ(monstre.getPosition(), positionInitiale);
    REQUIRE_EQ(monstre.getPV(), pvInitiaux);
    REQUIRE_EQ(monstre.getForce(), forceInitiale);
    }

    TEST_CASE("Test de la méthode subirDegats de Monstre avec de petits nombres") {
    Monstre monstre(point(1, 1), 10, 5);
    int degats = 3;
    monstre.subirDegats(degats);
    REQUIRE_EQ(monstre.getPV(), 7);  // Supposons que les PV initiaux étaient de 10
    // Tester que les PV ne tombent pas en dessous de 0
    monstre.subirDegats(10);
    REQUIRE_EQ(monstre.getPV(), 0);
	}


    TEST_CASE("Test de la méthode attaquer") {
        Aventurier aventurier(point(1, 1), 100, 10);
        Monstre monstre(point(1, 2), 50);

        monstre.attaquer(aventurier);

        int pvRestantsAventurier = aventurier.getPV();
        int pointsDeForceMonstre = monstre.getForce();
        REQUIRE_EQ(pvRestantsAventurier, 100 - pointsDeForceMonstre); // L'aventurier devrait subir les dégâts du monstre
    }

    TEST_CASE("Test de la méthode getSymbole") {
        Monstre monstre(point(1, 1), 100, 10);

        char symboleMonstre = monstre.getSymbole();

        REQUIRE_EQ(symboleMonstre, 'M'); // Le symbole du monstre doit être 'M'
    }

    TEST_CASE("Test de la méthode getPosition") {
        Monstre monstre(point(5, 10), 100, 10);

        point positionMonstre = monstre.getPosition();

        REQUIRE_EQ(positionMonstre, point(5, 10)); // La position du monstre doit être égale à la position initiale
    }

}



