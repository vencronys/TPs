#include "Compte.h"
#include <iostream>
#include <cstring>

void Compte::InitilizeCompte(const int &numeroCompte, const char* nomClient, const double &solde)
{
    m_numeroCompte = numeroCompte;
    strcpy(m_nomClient, nomClient);
    m_solde = solde;
}

void Compte::Deposer(const double &montant)
{
    m_solde += montant;
}

void Compte::Retirer(const double &montant)
{
    m_solde -= montant;
}

void Compte::Consulter() const
{
    std::cout << "Numero de compte: " << m_numeroCompte << std::endl;
    std::cout << "Nom du client: " << m_nomClient << std::endl;
    std::cout << "Solde: " << m_solde << std::endl;
}

int Compte::GetNumeroCompte() const
{
    return m_numeroCompte;
}

const char* Compte::GetNomClient() const
{
    return m_nomClient;
}

double Compte::GetSolde() const
{
    return m_solde;
}

