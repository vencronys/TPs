#pragma once

class Compte
{
public:
    void InitilizeCompte(const int &numeroCompte, const char* nomClient, const double &solde);
    void Deposer(const double &montant);
    void Retirer(const double &montant);
    void Consulter() const;

    int GetNumeroCompte() const;
    const char* GetNomClient() const;
    double GetSolde() const;
private:
    int m_numeroCompte;
    char m_nomClient[30];
    double m_solde;
};
