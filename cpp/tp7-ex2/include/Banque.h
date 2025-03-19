#pragma once

#include "Compte.h"

class Banque {
public:
    Banque(int capacity = 10);
    ~Banque();

    void AddCompte(const Compte &compte);
    void RemoveCompte(const int &ID);
    void PrintComptes() const;

private:
    Compte *m_comptes;
    int m_size;
    int m_capacity;
};
