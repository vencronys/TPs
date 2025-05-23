#include "Technicien.h"


const double Technicien::s_BASE = 1500.0;
const double Technicien::s_PART = 0.05;
const double Technicien::s_GIAN_UNITE = 1337.4;

Technicien::Technicien(const char *nom, const char *prenom, const int &age,
                       const int &anciennete, const int &nb_unite_produite)
    : Employe(nom, prenom, age, anciennete) {
    m_nb_unite_produite = nb_unite_produite;
}

Technicien::Technicien(const Technicien &technicien) : Employe(technicien) {
    m_nb_unite_produite = technicien.m_nb_unite_produite;
}

Technicien::~Technicien() {}

Technicien &Technicien::operator=(const Technicien &technicien) {
    Employe::operator=(technicien);
    m_nb_unite_produite = technicien.m_nb_unite_produite;
    return *this;
}

double Technicien::calculer_base_salaire() const {
    return Technicien::s_BASE + m_nb_unite_produite * Technicien::s_PART * Technicien::s_GIAN_UNITE;
}
