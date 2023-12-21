#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H




class Equipement
{
    public:
        Equipement(int soliditer);
        virtual ~Equipement()=default;
        bool utiliser();
        // void reparer(int pieces);


    protected:
        int soliditeActuelle;
        int soliditeMax;



};

#endif // EQUIPEMENT_H
