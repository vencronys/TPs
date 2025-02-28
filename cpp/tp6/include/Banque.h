#pragma once
#include "Compte.h"

class Banque {
public:
    void ShowComptes() const;
    void Add(Compte compte);
    void Delete(const int &numero);
    Compte GetCompte(const int &numero);
private:
    static int s_nbComptes;
    Compte m_agence[1000];
};
