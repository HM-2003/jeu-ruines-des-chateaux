#ifndef TYPEEQUIPEMENT_H
#define TYPEEQUIPEMENT_H


class typeEquipement
{
    public:
        typeEquipement();
        virtual ~typeEquipement();
       virtual int PointDeDurabilite()=0;
       virtual int PointDeForce()=0;

    protected:

    private:
        string type;
};

#endif // TYPEEQUIPEMENT_H
