#ifndef EPEE_H
#define EPEE_H
#include"typeEquipement.h"

class epee : public typeEquipement
{
    public:
        epee();
        virtual ~epee();
        int PointDeDurabilite() override;
        int PointDeForce() override;

    protected:

    private:
};

#endif // EPEE_H
