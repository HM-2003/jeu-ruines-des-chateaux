#include "Armure.h"
#include <cstdlib>
#include <ctime>

Armure::Armure(int soliditeInitiale) : Equipement(soliditeInitiale) {
   
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

void Armure::utiliser() {
   
    if ((std::rand() % 100) >= 20) {
        deteriorer();
    }
}

Armure::~Armure() {
    }
char Armure::getSymbole() const {
   return ']';
}
