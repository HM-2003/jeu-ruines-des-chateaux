#ifndef AVENTURIER_H
#define AVENTURIER_H
#include"equipement.h"
#include"point.h"
#include<vector>
#include"Monstre.h"



class aventurier
{
    public:
        aventurier(const geom::point& position, int pointDeVie=20,int pointdeforce=10);
        geom::point getPosition();
        void deeplacerVersGauche();
        void deplacerVersDroite();
        void deplacerVersHaut();
        void deplacerVersBas();
        void attaquerMonstre(std::vector<Monstre>& monstres);
        //void ramasserPieces(int pieces);
        void ramasserAmulette();
        void recevoirDegats(int degats);
        bool estVivant() const;

    protected:
    private:
        int PointDeVie ;
        int PointDeForce;
       bool PossedeAmulette;
       geom::point Position;

};

#endif // AVENTURIER_H
