#include "Epee.h"

Epee::Epee(int soliditeInitiale) : Equipement(soliditeInitiale) {}

void Epee::utiliser() {
    deteriorer(); // L'�p�e se d�t�riore � chaque utilisation
}
  char Epee::getSymbole() const {
   return '-';
}
Epee::~Epee() {
}
#include "Epee.h"
