#pragma once
#include "Commercial.h"

class Vendeur : public Commercial {
  public:
    Vendeur(const char *nom = "NILL", const char *prenom = "NILL",
            const int &age = -1, const int &anciennete = -1,
            const double &chiffre_affaire = -1);
    Vendeur(const Vendeur &);
    virtual ~Vendeur();
    Vendeur &operator=(const Vendeur &);
    virtual void afficher() const override {
        Employe::afficher();
        std::cout << "Nombre d'heurs: " << m_chiffre_affaire
                  << ", Profession: Vendeur\n";
    };
};