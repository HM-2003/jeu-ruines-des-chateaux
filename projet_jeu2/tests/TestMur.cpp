#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Mur.h"
#include "point.h"

TEST_SUITE("Tests la classe Mur") {
    
    TEST_CASE("Test le Constructeur de Mur") {
        geom::point position(5, 10);
        geom::Mur mur(position);

        CHECK(mur.getPosition() == position);
    }

    TEST_CASE("Tester la methode getPosition") {
        geom::point position(5, 10);
        geom::Mur mur(position);

        CHECK(mur.getPosition() == position);
    }

    TEST_CASE("Tester la methode getSymbole") {
        geom::Mur mur(geom::point(0, 0));

        CHECK(mur.getSymbole() == '#');
    }
    
}
