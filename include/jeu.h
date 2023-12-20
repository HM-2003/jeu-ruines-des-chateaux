#ifndef JEU_H
#define JEU_H
#include"terrain.h"
#include"aventurier.h"
#include"monstre.h"
#include"amulette.h"

class jeu
{
    public:
        jeu();
        virtual ~jeu();
        void jouer();
        void deplacerAventurier(direction& Direction);
        void attaquerMonstre();
        void ramasserAmulette();
        void ramasserPieces();

    protected:

    private:
        terrain Terrain;
        aventurier Aventurier;
        vector<monstre> Monstres;
        amulette Amulette;

};

#endif // JEU_H
