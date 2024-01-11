#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "MonstreAveugle.h"
#include "point.h"
#include <cstdlib>  // Pour rand()

namespace geom {
    TEST_CASE("Test du constructeur de MonstreAveugle") {
        point positionInitiale(3, 3);
        int pvInitiaux = 10;
        int forceInitiale = 5;
        MonstreAveugle monstreAveugle(positionInitiale, pvInitiaux, forceInitiale);

        CHECK(monstreAveugle.getPosition() == positionInitiale);
        CHECK(monstreAveugle.getPV() == pvInitiaux);
        CHECK(monstreAveugle.getForce() == forceInitiale);
    }

    TEST_CASE("Test de la méthode deplacer de MonstreAveugle") {
        srand(0);  // Fixer la graine pour la reproductibilité des tests
        point positionInitiale(3, 3);
        MonstreAveugle monstreAveugle(positionInitiale, 10, 5);

        monstreAveugle.deplacer();
        point nouvellePosition = monstreAveugle.getPosition();

        // Vérifier que la position a changé. Notez que cela dépend de la graine de rand()
        CHECK(nouvellePosition != positionInitiale);
    }

    TEST_CASE("Test de la méthode getSymbole de MonstreAveugle") {
        MonstreAveugle monstreAveugle(point(3, 3), 10, 5);

        CHECK(monstreAveugle.getSymbole() == 'V');
    }
}
