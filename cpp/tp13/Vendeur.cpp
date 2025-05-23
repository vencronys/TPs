#include "Vendeur.h"

Vendeur::Vendeur(const char *nom, const char *prenom,
        const int &age, const int &anciennete,
        const double &chiffre_affaire)
    : Commercial(nom, prenom, age, anciennete, chiffre_affaire) {}

Vendeur::Vendeur(const Vendeur &vendeur) : Commercial(vendeur) {}

Vendeur::~Vendeur() {}

Vendeur &Vendeur::operator=(const Vendeur &vendeur) {
    Commercial::operator=(vendeur);
    return *this;
}