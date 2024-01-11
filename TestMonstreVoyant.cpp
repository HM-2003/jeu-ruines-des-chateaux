#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Aventurier.h"
#include "MonstreVoyant.h"

using geom::point;

TEST_SUITE("Tests pour la classe MonstreVoyant") {
    
    TEST_CASE("Test du constructeur de MonstreVoyant") {
        point positionInitiale(1, 1);
        int pvInitiaux = 50;
        int forceInitiale = 10;
        
        MonstreVoyant monstreVoyant(positionInitiale, pvInitiaux, forceInitiale);
        
        REQUIRE_EQ(monstreVoyant.getPosition(), positionInitiale);
        REQUIRE_EQ(monstreVoyant.getPV(), pvInitiaux);
        REQUIRE_EQ(monstreVoyant.getForce(), forceInitiale);
    }
    TEST_CASE("Test de la méthode deplacer de MonstreVoyant") {
      TEST_CASE("déplacement vers le haut") {
        point positionInitiale(1, 1);
        int pvInitiaux = 50;
        int forceInitiale = 10;

        MonstreVoyant monstreVoyant(positionInitiale, pvInitiaux, forceInitiale);
        point positionAventurier(1, 0); // L'aventurier est en haut

        monstreVoyant.deplacer(positionAventurier);

        point nouvellePosition = monstreVoyant.getPosition();
        REQUIRE_EQ(nouvellePosition, point(1, 0)); // Le monstre doit se déplacer vers le haut
       }

      TEST_CASE("déplacement vers le bas") {
        point positionInitiale(1, 1);
        int pvInitiaux = 50;
        int forceInitiale = 10;

        MonstreVoyant monstreVoyant(positionInitiale, pvInitiaux, forceInitiale);
        point positionAventurier(1, 3); // L'aventurier est en bas

        monstreVoyant.deplacer(positionAventurier);

        point nouvellePosition = monstreVoyant.getPosition();
        REQUIRE_EQ(nouvellePosition, point(1, 2)); // Le monstre doit se déplacer d'une unité vers le bas
      }

      TEST_CASE("déplacement vers la gauche") {
        point positionInitiale(1, 1);
        int pvInitiaux = 50;
        int forceInitiale = 10;

        MonstreVoyant monstreVoyant(positionInitiale, pvInitiaux, forceInitiale);
        point positionAventurier(0, 1); // L'aventurier est à gauche

        monstreVoyant.deplacer(positionAventurier);

        point nouvellePosition = monstreVoyant.getPosition();
        REQUIRE_EQ(nouvellePosition, point(0, 1)); // Le monstre doit se déplacer vers la gauche
      }

      TEST_CASE("déplacement vers la droite") {
        point positionInitiale(1, 1);
        int pvInitiaux = 50;
        int forceInitiale = 10;

        MonstreVoyant monstreVoyant(positionInitiale, pvInitiaux, forceInitiale);
        point positionAventurier(3, 1); // L'aventurier est à droite

        monstreVoyant.deplacer(positionAventurier);

        point nouvellePosition = monstreVoyant.getPosition();
        REQUIRE_EQ(nouvellePosition, point(2, 1)); // Le monstre se déplace d'une unité vers la droite
      }

      TEST_CASE("aventurier trop loin, pas de deplacement") {
        point positionInitiale(1, 1);
        int pvInitiaux = 50;
        int forceInitiale = 10;

        MonstreVoyant monstreVoyant(positionInitiale, pvInitiaux, forceInitiale);
        point positionAventurier(10, 10); // L'aventurier est loin

        monstreVoyant.deplacer(positionAventurier);

        point nouvellePosition = monstreVoyant.getPosition();
        REQUIRE_EQ(nouvellePosition, positionInitiale); // Le monstre ne doit pas se déplacer car l'aventurier est trop loin
      }
   }
    
    TEST_CASE("Test de la méthode attaquer de MonstreVoyant") {
        Aventurier aventurier(point(1, 1), 100, 10);
        MonstreVoyant monstreVoyant(point(1, 2), 50);

        monstreVoyant.attaquer(aventurier);

        int pvRestantsAventurier = aventurier.getPV();
        int pointsDeForceMonstre = monstreVoyant.getForce();
        REQUIRE_EQ(pvRestantsAventurier, 100 - pointsDeForceMonstre); // L'aventurier devrait subir les dégâts du MonstreVoyant
    }

    TEST_CASE("Test de la méthode getSymbole de MonstreVoyant, Le symbole du MonstreVoyant doit être 'M'") {
        MonstreVoyant monstreVoyant(point(1, 1), 100, 10);

        char symboleMonstreVoyant = monstreVoyant.getSymbole();

        REQUIRE_EQ(symboleMonstreVoyant, 'M'); 
    }

    TEST_CASE("Test de la méthode getPosition de MonstreVoyant") {
        MonstreVoyant monstreVoyant(point(5, 10), 100, 10);

        point positionMonstreVoyant = monstreVoyant.getPosition();

        REQUIRE_EQ(positionMonstreVoyant, point(5, 10)); // La position du MonstreVoyant doit être égale à la position initiale
    }
}
