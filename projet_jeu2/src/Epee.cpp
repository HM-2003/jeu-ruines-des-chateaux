#include "Epee.h"

Epee::Epee(int soliditeInitiale) : Equipement(soliditeInitiale) {}

void Epee::utiliser() {
    deteriorer(); // L'épée se détériore à chaque utilisation
}
  char Epee::getSymbole() const {
   return '-';
}
Epee::~Epee() {
}
#include "Epee.h"
