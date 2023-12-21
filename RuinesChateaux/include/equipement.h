#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H
#include"armure.h"
#include"epee.h"



class equipement
{
    public:
        equipement();
        virtual ~equipement();
        virtual void PointDeDurabilite()=0;
        virtual void PointDeForce()=0;


    protected:

    private:
        int PointForce;
        int PointDurabilite;


};

#endif // EQUIPEMENT_H
