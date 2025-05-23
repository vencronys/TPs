#pragma once
#include "Commercial.h"

class Representant : public Commercial {
  private:
    int m_nb_heurs;
    static const double s_BASE_SALAIRE_HORAIRE;

  public:
    Representant(const char *nom = "NILL", const char *prenom = "NILL",
                 const int &age = -1, const int &anciennete = -1,
                 const double &chiffre_affaire = -1, const int &nb_heurs = -1);
    Representant(const Representant &);
    virtual ~Representant();
    Representant &operator=(const Representant &);
    virtual void afficher() const override {
        Employe::afficher();
        std::cout << "Chiffre d'affaire: " << m_chiffre_affaire
                  << ", Nombre d'heurs: " << m_nb_heurs
                  << ", Profession: Representant\n";
    };
    double calculer_base_salaire() const;
};