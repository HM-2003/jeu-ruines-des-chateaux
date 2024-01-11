#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Epee.h"

TEST_CASE("Test la classe Epee") {
    SUBCASE("Test du Constructeur") {
        Epee epee(10);
        REQUIRE_EQ(epee.getSolidite(), 10);
    }

    SUBCASE("Test de la méthode utiliser") {
        Epee epee(10);
        int soliditeInitiale = epee.getSolidite();
        epee.utiliser();
        REQUIRE_EQ(epee.getSolidite(), soliditeInitiale - 1);
    }

    SUBCASE("Test de la méthode getSymbole") {
        Epee epee(10);
        REQUIRE_EQ(epee.getSymbole(), '-');
    }
}
