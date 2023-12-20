#ifndef ARMURE_H
#define ARMURE_H
#include"typeEquipement.h"

class armure : public typeEquipement
{
    public:
        armure();
        virtual ~armure();
        int PointDeDurabilite() override;

    protected:

    private:
};

#endif // ARMURE_H
