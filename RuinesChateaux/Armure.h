#ifndef ARMURE_H
#define ARMURE_H

#include "Equipement.h"

class Armure : public Equipement {
public:
    Armure(int soliditeInitiale);
    void utiliser() override;
    virtual ~Armure();
     char getSymbole() const;
    private:
    char symbole;
};

#endif // ARMURE_H

