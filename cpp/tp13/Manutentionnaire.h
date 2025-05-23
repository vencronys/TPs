#pragma once
#include "Employe.h"

class Manutentionnaire : public Employe {
  private:
    int m_nb_heurs;
    static const double s_BASE_SALAIRE_HORAIRE;

  public:
    Manutentionnaire(const char *nom = "NILL", const char *prenom = "NILL",
                     const int &age = -1, const int &anciennete = -1,
                     const int &nb_heurs = -1);

    Manutentionnaire(const Manutentionnaire &);
    virtual ~Manutentionnaire();
    Manutentionnaire &operator=(const Manutentionnaire &);

    virtual void afficher() const override {
        Employe::afficher();
        std::cout << "Nombre d'heurs: " << m_nb_heurs
                  << ", Profession: Manutentionnaire\n";
    };

    virtual double calculer_base_salaire() const;
};