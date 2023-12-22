#include "terrain.h"

terrain::terrain(aventurier& Av,Monstre& Mo,amulette& Am,geom::Mur& mr):Aventurier{Av},Monstre{Mo},Amulette{Am},mur{mr}{}

terrain::~terrain()
{
    //dtor
}

void terrain::ajouterMonstre()
{
    //dtor
}

void terrain::ajouterAventurier(point& pos)
{
    aventurier(pos);
}

void terrain::ajouterAmulette(point& pos)
{
    amulette(pos);
}


void terrain::ajouterMur()
{

}
