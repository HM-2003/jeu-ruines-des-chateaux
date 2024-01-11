#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include"doctest.h"
#include "Equipement.h"

TEST_CASE("Test du constructeur de Equipement") {
    int soliditeInitiale = 10;
    Equipement equipement(soliditeInitiale);

    CHECK(equipement.getSolidite() == soliditeInitiale);
}

TEST_CASE("Test de la méthode deteriorer de Equipement") {
    Equipement equipement(3);

    equipement.deteriorer();
    CHECK(equipement.getSolidite() == 2);  // Suppose solidite initiale de 3

    // Tester que la solidite ne devient pas négative
    for(int i = 0; i < 10; i++) {
        equipement.deteriorer();
    }
    CHECK(equipement.getSolidite() == 0);
}

TEST_CASE("Test de la méthode reparer de Equipement") {
TEST_CASE("Test de la méthode reparer de Equipement avec solidite initiale > 0") {
    Equipement equipement(1);
    int nbPieces = 3;

    equipement.reparer(nbPieces);
    CHECK(equipement.getSolidite() == 4);  // Suppose solidite initiale de 1
}

TEST_CASE("Test de la méthode reparer de Equipement avec solidite initiale = 0") {
    Equipement equipement(0);
    int nbPieces = 3;

    equipement.reparer(nbPieces);
    CHECK(equipement.getSolidite() == 3);
}
}