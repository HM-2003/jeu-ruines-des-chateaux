#ifndef MONSTRE_H
#define MONSTRE_H
#include"typeMonstre.h"
#include"direction.h"


class monstre : public typeMonstre
{
    public:
        monstre();
        virtual ~monstre();
        void attaquer( aventurier& Aventurier);

    protected:

    private:
        int PointDeVie ;
        int PointDeForce;
        int PourcentageHabilete;
        int PositionX;
        int PositionY;
        typeMonstre typeMO;




};

#endif // MONSTRE_H
