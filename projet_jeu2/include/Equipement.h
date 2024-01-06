#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H

class Equipement {
public:
    Equipement(int soliditeInitiale);
    virtual void deteriorer();
    virtual void utiliser() = 0; 
    void reparer(int nbPieces);
    int getSolidite() const;
    virtual ~Equipement();

protected:
    int solidite;
};

#endif // EQUIPEMENT_H

