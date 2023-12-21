#ifndef TERRAIN_H
#define TERRAIN_H
#include"aventurier.h"
#include"monstre.h"
#include"amulette.h"
#include"mur.h"




class terrain
{
    public:
        terrain(aventurier& Av,Monstre& Mo,amulette& Am,Mur& mr);
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
        Mur mur;



};

#endif // TERRAIN_H
