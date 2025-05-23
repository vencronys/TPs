#include "Commercial.h"

const double Commercial::s_BASE = 1500.0;
const double Commercial::s_PART = 0.05;

Commercial::Commercial(const char *nom, const char *prenom, const int &age,
                       const int &anciennete, const double &chiffre_affaire)
    : Employe(nom, prenom, age, anciennete) {
    m_chiffre_affaire = chiffre_affaire;
}

Commercial::Commercial(const Commercial &commercial) : Employe(commercial) {
    m_chiffre_affaire = commercial.m_chiffre_affaire;
}

Commercial::~Commercial() {}

Commercial &Commercial::operator=(const Commercial &commercial) {
    Employe::operator=(commercial);
    m_chiffre_affaire = commercial.m_chiffre_affaire;
    return *this;
}

double Commercial::calculer_base_salaire() const {
    return Commercial::s_BASE + m_chiffre_affaire * Commercial::s_PART;
}
