#ifndef EPEE_H
#define EPEE_H
#include"equipement.h"

class Epee :public Equipement
{

public:
    Epee(int solidite);
    virtual ~Epee()=default;
    int attaquer();

    private:
};


#endif // EPEE_H
