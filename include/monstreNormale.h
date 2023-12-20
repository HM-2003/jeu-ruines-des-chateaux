#ifndef MONSTRENORMALE_H
#define MONSTRENORMALE_H
#include"typeMonstre.h"


class monstreNormale : public typeMonstre
{
    public:
        monstreNormale();
        virtual ~monstreNormale();
        void deplacer(direction& Direction) override;

    protected:

    private:
};

#endif // MONSTRENORMALE_H
