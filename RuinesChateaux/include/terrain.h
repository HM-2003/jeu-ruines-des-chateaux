#ifndef TERRAIN_H
#define TERRAIN_H
#include"aventurier.h"
#include"Monstre.h"
#include"amulette.h"
#include"Mur.h"
#include"point.h"
#include<vector>




class terrain
{
    public:
        terrain(aventurier& Av,Monstre& Mo,amulette& Am,geom::Mur& mr);
        virtual ~terrain();
        void ajouterMonstre(Monstre* Pmonstre);
        void ajouterAventurier(geom::point& pos);
        void ajouterAmulette(geom::point& pos);
        //void ajouterMur(geom::Mur& pos);


    protected:

    private:
        aventurier Aventurier;
        std::vector<Monstre*> Monstres;
        amulette Amulette;
        geom::Mur mur;



};

#endif // TERRAIN_H
