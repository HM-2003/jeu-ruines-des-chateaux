#ifndef MONSTRE_H
#define MONSTRE_H
#include"point.h";
#include "aventurier.h";



class Monstre     
{
    public:
    	Monstre();
    	virtual~Monstre();
        virtual void attaquerAvent( int PointdeAventurier)const;
        virtual void deplacer()const ; 
		virtual void recevoirDegats(int degats)const;
		bool estVaincu(); 


  
    
    	
     private:
        int PointDeVie;
        int PointDeForce;
        point position;
        int Pointdurabilite;
        int degats;
       
};

#endif // MONSTRE_H