#ifndef ARMURE_H
#define ARMURE_H

#include"equipement.h"


class Armure : public Equipement
{

    public:
        Armure(int solidite);
        virtual ~Armure()=default;
        void recoisAttaque(int pointdeforce);


    protected:

    private:
};

#endif // ARMURE_H
