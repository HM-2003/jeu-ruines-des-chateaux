#ifndef AVENTURIER_H
#define AVENTURIER_H
#include"direction.h"
#include"equipement.h"



class aventurier
{
    public:
        aventurier();
        virtual ~aventurier();
        void deplacer(direction& Direction);
        void attaquer(monstre& Monstre);
        void ramasserPieces(int pieces);
        void ramasserAmulette();

    protected:

    private:
        int PointDeVie ;
        int PointDeForce;
        int Bource;
        int PositionX;
        int PositionY;
        equipement Equipement;
};

#endif // AVENTURIER_H
