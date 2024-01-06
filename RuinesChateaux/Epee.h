#ifndef EPEE_H
#define EPEE_H

#include "Equipement.h"

class Epee : public Equipement {
public:
    Epee(int soliditeInitiale);
    void utiliser() override;
    virtual ~Epee();
     char getSymbole() const;
    private:
    char symbole;
};

#endif // EPEE_H

