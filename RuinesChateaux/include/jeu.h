#ifndef JEU_H
#define JEU_H
#include"terrain.h"
#include"aventurier.h"
#include"Monstre.h"
#include"amulette.h"
#include"direction.h"
#include<vector>

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
       std::vector<Monstre> Monstres;
        amulette Amulette;

};

#endif // JEU_H
