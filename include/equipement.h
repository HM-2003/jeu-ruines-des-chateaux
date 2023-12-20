#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H
#include"typeEquipement.h"


class equipement : public typeEquipement
{
    public:
        equipement();
        virtual ~equipement();

    protected:

    private:
        int PointDeForce;
        int PointDeDurabilite;
        typeEquipement typeEQ;
};

#endif // EQUIPEMENT_H
