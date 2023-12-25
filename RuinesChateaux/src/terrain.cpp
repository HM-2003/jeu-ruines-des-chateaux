#include "terrain.h"

terrain::terrain(aventurier& Av,Monstre& Mo,amulette& Am,geom::Mur& mr):Aventurier{Av},Monstre{Mo},Amulette{Am},mur{mr}{}

terrain::~terrain()
{
    //dtor
}

void terrain::ajouterMonstre(Monstre* Pmonstre)
{
    Monstres.push_back(Pmonstre);
}

void terrain::ajouterAventurier(geom::point& pos)
{
    Aventurier =aventurier(pos);
}

void terrain::ajouterAmulette(geom::point& pos)
{
    Amulette = amulette(pos);
}


/*void terrain::ajouterMur(geom::Mur& pos)
{
   Mur(pos);
}
*/
