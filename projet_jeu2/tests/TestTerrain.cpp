#include "doctest.h"
#include "Terrain.h"

TEST_CASE("Test de la création et de l'accès à la largeur et à la hauteur du Terrain") {
    geom::Terrain terrain(10, 5);

    REQUIRE_EQ(terrain.getLargeur(), 10);
    REQUIRE_EQ(terrain.getHauteur(), 5);
}

TEST_CASE("Test de la méthode placerMur de Terrain") {
    geom::Terrain terrain(10, 5);
    geom::Mur mur(geom::point(2, 3));

    terrain.placerMur(mur);

    REQUIRE_EQ(terrain.estMur(geom::point(2, 3)), true);
    REQUIRE_EQ(terrain.estMur(geom::point(4, 4)), false); // Vérifie que d'autres cases ne sont pas des murs
}

TEST_CASE("Test de la méthode ajouterMonstre de Terrain") {
    geom::Terrain terrain(10, 5);
    geom::Monstre* monstre = new geom::Monstre(geom::point(5, 2), 50, 10);

    terrain.ajouterMonstre(monstre);

    REQUIRE_EQ(terrain.estMonstre(geom::point(5, 2)), true);
    REQUIRE_EQ(terrain.estMonstre(geom::point(3, 4)), false);//c'est pas une Monstre
}

TEST_CASE("Test de la méthode placerAventurier de Terrain") {
    geom::Terrain terrain(10, 5);
    geom::Aventurier aventurier(geom::point(3, 2));

    terrain.placerAventurier(&aventurier);

    REQUIRE_EQ(terrain.estAventurier(geom::point(3, 2)), true);
    REQUIRE_EQ(terrain.estAventurier(geom::point(7, 1)), false);//C'est pas une Aventurier
}

TEST_CASE("Test de la méthode placerAmulette de Terrain") {
    geom::Terrain terrain(10, 5);
    geom::Amulette amulette(geom::point(7, 4));

    terrain.placerAmulette(&amulette);

    REQUIRE_EQ(terrain.estAmulette(geom::point(7, 4)), true);
    REQUIRE_EQ(terrain.estAmulette(geom::point(1, 3)), false);//C'est pas une Amulette
}

