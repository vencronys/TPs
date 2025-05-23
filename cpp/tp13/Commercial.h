#pragma once
#include "Employe.h"

class Commercial : public Employe {
  protected:
    double m_chiffre_affaire;
    const static double s_BASE;
    const static double s_PART;

  public:
    Commercial(const char *nom = "NILL", const char *prenom = "NILL",
               const int &age = -1, const int &anciennete = -1,
               const double &chiffre_affaire = -1);

    Commercial(const Commercial &);
    virtual ~Commercial();
    Commercial &operator=(const Commercial &);

    virtual void afficher() const override {
        Employe::afficher();
        std::cout << "Chiffre d'affaire: " << m_chiffre_affaire
                  << ", Profession: Commercial\n";
    };

    double calculer_base_salaire() const;
};