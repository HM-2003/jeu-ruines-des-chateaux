#ifndef EPEE_H
#define EPEE_H
#include "equipement.h"

class epee : public equipement
{
public:
    epee();
    virtual ~epee();
    void PointDeDurabilite() override;
    void PointDeForce() override;

protected:

private:
};

#endif // EPEE_H
