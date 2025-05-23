#include "Manutentionnaire.h"

const double Manutentionnaire::s_BASE_SALAIRE_HORAIRE = 1500.0;

Manutentionnaire::Manutentionnaire(const char *nom, const char *prenom,
                             const int &age,
                       const int &anciennete, const int &nb_heurs)
    : Employe(nom, prenom, age, anciennete) {
    m_nb_heurs = nb_heurs;
}

Manutentionnaire::Manutentionnaire(const Manutentionnaire &manutentionnaire)
    : Employe(manutentionnaire) {
    m_nb_heurs = manutentionnaire.m_nb_heurs;
}

Manutentionnaire::~Manutentionnaire() {}

Manutentionnaire &
Manutentionnaire::operator=(const Manutentionnaire &manutentionnaire) {
    Employe::operator=(manutentionnaire);
    m_nb_heurs = manutentionnaire.m_nb_heurs;
    return *this;
}

double Manutentionnaire::calculer_base_salaire() const {
    return Manutentionnaire::s_BASE_SALAIRE_HORAIRE * m_nb_heurs;
           
}