#ifndef TYPEMONSTRE_H
#define TYPEMONSTRE_H


class typeMonstre
{
    public:
        typeMonstre();
        virtual ~typeMonstre();
       virtual void deplacer(direction& Direction)=0;

    protected:

    private:
        string type;
};

#endif // TYPEMONSTRE_H
