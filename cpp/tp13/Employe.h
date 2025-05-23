#pragma once
#include <iostream>

class Employe {

  protected:
    char *m_nom;
    char *m_prenom;
    int m_age;
    int m_anciennete;

  public:
    Employe(const char *nom = "NILL", const char *prenom = "NILL",
            const int &age = -1, const int &anciennete = -1);
    Employe(const Employe &);
    virtual ~Employe();
    Employe &operator=(const Employe &);

    virtual void afficher() const {
        std::cout << "Nom: " << m_nom << ", Prenom: " << m_prenom
                  << ", Age: " << m_age << ", Anciennete: " << m_anciennete
                  << " ";
    }

    virtual double calculer_base_salaire() const = 0;

    double calculer_salaire() const;
};