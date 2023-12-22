#ifndef TERRAIN_H
#define TERRAIN_H
#include"aventurier.h"
#include"Monstre.h"
#include"amulette.h"
#include"Mur.h"




class terrain
{
    public:
        terrain(aventurier& Av,Monstre& Mo,amulette& Am,geom::Mur& mr);
        virtual ~terrain();
        void ajouterMonstre();
        void ajouterAventurier();
        void ajouterAmulette();
        void ajouterMur();


    protected:

    private:
        aventurier Aventurier;
        Monstre Monstre;
        amulette Amulette;
        geom::Mur mur;



};

#endif // TERRAIN_H
