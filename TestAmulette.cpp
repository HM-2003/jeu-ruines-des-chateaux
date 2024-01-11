#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Amulette.h"
#include "point.h"

TEST_SUITE("Tester pour la classe Amulette") {
    
    TEST_CASE("Tester le constructeur de la class Amulette") {
        geom::point position(5, 10);
        geom::Amulette amulette(position);

        CHECK(amulette.getPosition() == position);
    }

    TEST_CASE("Tester la methode getPosition avec une position différente") {
        geom::point positionDif(3, 7);
        geom::Amulette amulette(positionDif);

        CHECK(amulette.getPosition() == positionDif);
    }

    TEST_CASE("Test de getSymbole") {
        geom::Amulette amulette(geom::point(0, 0));

        CHECK(amulette.getSymbole() == '@');
    }
    
} 
