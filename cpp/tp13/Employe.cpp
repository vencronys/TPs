#include "Employe.h"
#include <cstringt.h>

Employe::Employe(const char *nom, const char *prenom, const int &age,
                 const int &anciennete) {
    size_t sizeNom = strlen(nom) + 1;
    size_t sizePrenom = strlen(prenom) + 1;
    m_nom = new char[sizeNom];
    m_prenom = new char[sizePrenom];
    strcpy_s(m_nom, sizeNom, nom);
    strcpy_s(m_prenom, sizePrenom, prenom);
    m_age = age;
    m_anciennete = anciennete;
}

Employe::Employe(const Employe &employe)
    : Employe(employe.m_nom, employe.m_prenom, employe.m_age,
              employe.m_anciennete) {}

Employe &Employe::operator=(const Employe &employe) {
    delete[] m_nom;
    delete[] m_prenom;
    size_t sizeNom = strlen(employe.m_nom) + 1;
    size_t sizePrenom = strlen(employe.m_prenom) + 1;
    m_nom = new char[sizeNom];
    m_prenom = new char[sizePrenom];
    strcpy_s(m_nom, sizeNom, employe.m_nom);
    strcpy_s(m_prenom, sizePrenom, employe.m_prenom);
    m_age = employe.m_age;
    m_anciennete = employe.m_anciennete;
    return *this;
}

Employe::~Employe() {
    delete[] m_nom;
    delete[] m_prenom;
}

double Employe::calculer_salaire() const {
    double salaire = calculer_base_salaire();
    for (int i = 0; i < m_anciennete; i++) {
        salaire += salaire * 0.1;
    }
    return salaire;
}
