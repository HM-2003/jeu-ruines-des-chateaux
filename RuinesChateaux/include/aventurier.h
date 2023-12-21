#ifndef AVENTURIER_H
#define AVENTURIER_H
#include"equipement.h"
#include"point.h"
#include"monstre.h"



class aventurier
{
    public:
        aventurier(const point& position, int pointDeVie=20,int pointdeforce=10);
        point Position();
        void deeplacerVersGauche();
        void deplacerVersDroite();
        void deplacerVersHaut();
        void deplacerVersBas();
        void attaquerMonstr(monstre& Monstre);
        //void ramasserPieces(int pieces);
        void ramasserAmulette();
        void recevoirDegats(int degats);
        bool estVivant() const;

    protected:
    private:
        int PointDeVie ;
        int PointDeForce;
       bool PossedeAmulette;
        point Position;

};

#endif // AVENTURIER_H
