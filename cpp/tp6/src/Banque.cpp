#include "Banque.h"
#include "Compte.h"
#include <iostream>
#include <cstring>

int Banque::s_nbComptes = 0;

void Banque::ShowComptes() const {
    std::cout << "Affichage de banque:" << std::endl;
    for (int i = 0; i < Banque::s_nbComptes; i++) {
        m_agence[i].Consulter();
    }
}

void Banque::Add(Compte compte) {
    m_agence[Banque::s_nbComptes++] = compte;
}

void Banque::Delete(const int &numero) {
    int i;
    for (i = 0; i < Banque::s_nbComptes; i++) {
        if (m_agence[i].GetNumeroCompte() == numero) {
            break;
        }
    }
    if (i < Banque::s_nbComptes) {
        for (int j = i; j < Banque::s_nbComptes-1; j++) {
            m_agence[j] = m_agence[j+1];
        }
        Banque::s_nbComptes--;
    }
}

Compte Banque::GetCompte(const int &numero) {
    for (int i = 0; i < Banque::s_nbComptes; i++) {
        if (m_agence[i].GetNumeroCompte() == numero) {
            return m_agence[i];
        }
    }
}
