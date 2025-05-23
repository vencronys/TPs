#include "Representant.h"

const double Representant::s_BASE_SALAIRE_HORAIRE = 1500.0;

Representant::Representant(const char *nom, const char *prenom, const int &age,
                           const int &anciennete, const double &chiffre_affaire,
                           const int &nb_heurs)
    : Commercial(nom, prenom, age, anciennete, chiffre_affaire) {
    m_nb_heurs = nb_heurs;
}

Representant::Representant(const Representant &representant)
    : Commercial(representant) {
    m_nb_heurs = representant.m_nb_heurs;
}

Representant::~Representant() {}

Representant &Representant::operator=(const Representant &representant) {
    Commercial::operator=(representant);
    m_nb_heurs = representant.m_nb_heurs;
    return *this;
}

double Representant::calculer_base_salaire() const {
    return Representant::s_BASE_SALAIRE_HORAIRE * m_nb_heurs;
}