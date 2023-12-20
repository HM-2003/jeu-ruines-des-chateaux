#ifndef MONSTREAVEUGLE_H
#define MONSTREAVEUGLE_H
#include"typeMonstre.h"


class monstreAveugle : public typeMonstre
{
    public:
        monstreAveugle();
        virtual ~monstreAveugle();
        void deplacer(direction& Direction) override;

    protected:

    private:
};

#endif // MONSTREAVEUGLE_H
