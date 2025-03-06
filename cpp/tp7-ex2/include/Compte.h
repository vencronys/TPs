#pragma once

class Compte {
public:
    Compte();
    Compte(const char *name, const double &balance);
    ~Compte();
    void Print() const;
    void PrintBalance() const;
    void Withdraw(const double &balance);
    void Deposit(const double &balance);

private:
    static int s_nextID;
    const int m_ID;
    char *m_name;
    double m_balance;
};
