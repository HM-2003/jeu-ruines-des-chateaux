#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Armure.h" 

TEST_SUITE("Tests pour la classe Armure") {
	TEST_CASE("Test du Constructeur") {
        int soliditeInitiale = 10;
        Armure armure(soliditeInitiale);
        REQUIRE_EQ(armure.getSolidite(), soliditeInitiale);
    }
    
    TEST_CASE("Test de la méthode utiliser avec détérioration") {
        Armure armure(20); // Solidité initiale de 20

        SECTION("Détérioration de l'armure") {
            int soliditeAvant = armure.getSolidite();
            armure.utiliser(); // Appel de la méthode utiliser

            // Avec un seed fixe (0), la détérioration est forcée
            std::srand(0);

            int soliditeApres = armure.getSolidite();

            REQUIRE_EQ(soliditeApres, soliditeAvant - 1); // L'armure doit perdre 1 de solidité
        }
    }
    

    TEST_CASE("Test de la méthode utiliser sans détérioration") {
        Armure armure(10); // Solidité initiale de 10

        SECTION("Pas de détérioration de l'armure") {
            int soliditeAvant = armure.getSolidite();

            // Avec un seed fixe (100), la détérioration est forcée à ne pas se produire
            std::srand(100);

            armure.utiliser(); // Appel de la méthode utiliser
            int soliditeApres = armure.getSolidite();

            REQUIRE_EQ(soliditeApres, soliditeAvant); // L'armure ne doit pas perdre de solidité
        }
    }
}

    SECTION("Test de la méthode getSymbole") {
        Armure armure(10);
        REQUIRE_EQ(armure.getSymbole(), ']');
    }

   
}


