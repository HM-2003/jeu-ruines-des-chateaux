#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include"Aventurier.h"

using geom::point;

TEST_SUITE("Tests pour la méthode deplacer de Aventurier") {

    TEST_CASE("Test deplacement vers le haut (w)") {
        Aventurier aventurier(point(1, 1), 100, 10);
        point nouvellePosition(1, 0);

        aventurier.deplacer('w');

        REQUIRE(aventurier.getPosition() == nouvellePosition);
    }

    TEST_CASE("Test deplacement vers le bas (s)") {
        Aventurier aventurier(point(1, 1), 100, 10);
        point nouvellePosition(1, 2);

        aventurier.deplacer('s');

        REQUIRE(aventurier.getPosition() == nouvellePosition);
    }

    TEST_CASE("Test deplacement vers la gauche (a)") {
        Aventurier aventurier(point(1, 1), 100, 10);
        point nouvellePosition(0, 1);

        aventurier.deplacer('a');

        REQUIRE(aventurier.getPosition() == nouvellePosition);
    }

    TEST_CASE("Test deplacement vers la droite (d)") {
        Aventurier aventurier(point(1, 1), 100, 10);
        point nouvellePosition(2, 1);

        aventurier.deplacer('d');

        REQUIRE(aventurier.getPosition() == nouvellePosition);
    }

    TEST_CASE("Test deplacement avec une direction non reconnue") {
        Aventurier aventurier(point(1, 1), 100, 10);
        point positionInitiale = aventurier.getPosition();

        aventurier.deplacer('x'); // Direction non reconnue

        REQUIRE(aventurier.getPosition() == positionInitiale); // La position ne doit pas changer
    }
}

TEST_SUITE("Tests pour la méthode subirDegats de Aventurier") {

    TEST_CASE("Test de subir des dégâts sans armure") {
        Aventurier aventurier(point(1, 1), 100, 10);

        aventurier.subirDegats(20);

        int pvRestants = aventurier.getPV();
        REQUIRE_EQ(pvRestants, 100 - 20); // Les PV doivent être réduits sans armure
    }

    TEST_CASE("Test de subir des dégâts avec armure") {
        Aventurier aventurier(point(1, 1), 100, 10);
        Armure armure(5);
        aventurier.equiperArmure(&armure);

        aventurier.subirDegats(20);

        int pvRestants = aventurier.getPV();
        REQUIRE_EQ(pvRestants, 100 - 20); // Les PV doivent être réduits malgré l'armure
        int soliditeArmure = armure.getSolidite();
        REQUIRE_EQ(soliditeArmure, 4); // L'armure a été utilisée
    }

    TEST_CASE("Test de subir des dégâts avec armure et utilisation") {
        Aventurier aventurier(point(1, 1), 100, 10);
        Armure armure(5);
        aventurier.equiperArmure(&armure);

        aventurier.subirDegats(20);

        int soliditeArmure = armure.getSolidite();
        REQUIRE_EQ(soliditeArmure, 4); // L'armure a été utilisée
    }

    TEST_CASE("Test de subir des dégâts mortels") {
        Aventurier aventurier(point(1, 1), 100, 10);

        aventurier.subirDegats(150); // Plus de PV que l'Aventurier a

        int pvRestants = aventurier.getPV();
        REQUIRE_EQ(pvRestants, 0); // Les PV ne peuvent pas être inférieurs à 0
    }
}

TEST_SUITE("Tests pour la méthode equiperEpee de Aventurier") {

    TEST_CASE("Test de l'équipement d'une épée") {
        Aventurier aventurier(point(1, 1), 100, 10);
        Epee epee(5);

        aventurier.equiperEpee(&epee);

        REQUIRE_EQ(aventurier.aUneEpee(), true); // L'aventurier doit avoir une épée équipée
    }

    TEST_CASE("Test de l'enlèvement de l'épée") {
        Aventurier aventurier(point(1, 1), 100, 10);
        Epee epee(5);
        aventurier.equiperEpee(&epee);

        aventurier.enleverEpee();

        REQUIRE_EQ(aventurier.aUneEpee(), false); // L'aventurier ne doit pas avoir d'épée équipée
    }
}

TEST_SUITE("Tests pour la méthode equiperArmure de Aventurier") {

    TEST_CASE("Test de l'équipement d'une armure") {
        Aventurier aventurier(point(1, 1), 100, 10);
        Armure armure(5);

        aventurier.equiperArmure(&armure);

        REQUIRE_EQ(aventurier.aUneArmure(), true); // L'aventurier doit avoir une armure équipée
    }

    TEST_CASE("Test de l'enlèvement de l'armure") {
        Aventurier aventurier(point(1, 1), 100, 10);
        Armure armure(5);
        aventurier.equiperArmure(&armure);

        aventurier.enleverArmure();

        REQUIRE_EQ(aventurier.aUneArmure(), false); // L'aventurier ne doit pas avoir d'armure équipée
    }
}

TEST_CASE("Test de la méthode getSymbole de Aventurier") {
    Aventurier aventurier(point(1, 1), 100, 10);

    char symboleAventurier = aventurier.getSymbole();

    REQUIRE_EQ(symboleAventurier, 'A'); // Le symbole retourné doit être 'A'
}


TEST_CASE("Test de la méthode getPosition de Aventurier") {
    Aventurier aventurier(point(5, 10), 100, 10);

    point positionAventurier = aventurier.getPosition();

    REQUIRE_EQ(positionAventurier, point(5, 10)); // La position retournée doit être égale à la position initiale
}


TEST_CASE("Test de la méthode getPV de Aventurier") {
    Aventurier aventurier(point(1, 1), 80, 10);

    int pvAventurier = aventurier.getPV();

    REQUIRE_EQ(pvAventurier, 80); // Les points de vie retournés doivent être égaux à 80
}


TEST_CASE("Test de la méthode getForce de Aventurier") {
    Aventurier aventurier(point(1, 1), 100, 15);

    int forceAventurier = aventurier.getForce();

    REQUIRE_EQ(forceAventurier, 15); // La force retournée doit être égale à 15
}


TEST_CASE("Test de la méthode getSymbole de Aventurier") {
    Aventurier aventurier(point(1, 1), 100, 10);

    char symboleAventurier = aventurier.getSymbole();

    REQUIRE_EQ(symboleAventurier, 'A'); // Le symbole retourné doit être 'A'
}


#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Aventurier.h"
#include "Monstre.h"

using geom::point;

TEST_SUITE("Tests pour la méthode attaquer de Aventurier") {

    TEST_CASE("Test d'attaque réussie sans épée") {
        Aventurier aventurier(point(1, 1), 100, 10);
        Monstre monstre(point(1, 2), 50);

        aventurier.attaquer(monstre);

        int pvRestants = monstre.getPV();
        REQUIRE_EQ(pvRestants, 50 - 10); // Dégâts de l'Aventurier sans épée
    }

    TEST_CASE("Test d'attaque réussie avec épée") {
        Aventurier aventurier(point(1, 1), 100, 10);
        Monstre monstre(point(1, 2), 50);
        Epee epee(5);
        aventurier.equiperEpee(&epee);

        aventurier.attaquer(monstre);

        int pvRestants = monstre.getPV();
        REQUIRE_EQ(pvRestants, 50 - (10 + 5)); // Dégâts de l'Aventurier avec épée
    }

    TEST_CASE("Test d'attaque réussie avec épée et utilisation") {
        Aventurier aventurier(point(1, 1), 100, 10);
        Monstre monstre(point(1, 2), 50);
        Epee epee(5);
        aventurier.equiperEpee(&epee);

        aventurier.attaquer(monstre);

        int soliditeEpee = epee.getSolidite();
        REQUIRE_EQ(soliditeEpee, 4); // L'épée a été utilisée
    }

    TEST_CASE("Test d'attaque échouée (trop loin)") {
        Aventurier aventurier(point(1, 1), 100, 10);
        Monstre monstre(point(1, 3), 50);

        aventurier.attaquer(monstre);

        int pvRestants = monstre.getPV();
        REQUIRE_EQ(pvRestants, 50); // Le monstre est trop loin, les PV ne doivent pas être réduits
    }
}




