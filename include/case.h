#ifndef CASE_H
#define CASE_H
#include"typeCase.h"


class case : public typeCase
{
    public:
        case();
        virtual ~case();
        virtual void afficherCase();

    protected:

    private:
        int positionX;
        int positionY;
        typeCase type;
};

#endif // CASE_H
