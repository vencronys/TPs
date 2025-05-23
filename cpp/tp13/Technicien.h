#pragma once
#include "Employe.h"

class Technicien : public Employe {
  private:
    int m_nb_unite_produite;
    const static double s_BASE;
    const static double s_PART;
    const static double s_GIAN_UNITE;

  public:
    Technicien(const char *nom = "NILL", const char *prenom = "NILL",
               const int &age = -1, const int &anciennete = -1,
               const int &nb_unite_produite = -1);

    Technicien(const Technicien &);
    virtual ~Technicien();
    Technicien &operator=(const Technicien &);

    virtual void afficher() const override {
        Employe::afficher();
        std::cout << "Nombre d'unite produite: " << m_nb_unite_produite
                  << ", Profession: Technicien\n";
    };

    double calculer_base_salaire() const;
};