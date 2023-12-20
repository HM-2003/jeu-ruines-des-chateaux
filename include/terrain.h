#ifndef TERRAIN_H
#define TERRAIN_H
#include"case.h"


class terrain : public case
{
    public:
        terrain();
        virtual ~terrain();
       void afficherterrain();

    protected:

    private:
        int tailleX;
        int tailleY;
        vector<case> cases;
};

#endif // TERRAIN_H
