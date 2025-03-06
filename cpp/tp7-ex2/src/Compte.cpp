#include "Compte.h"
#include <cstring>
#include <iostream>

int Compte::s_nextID = 0;

Compte::Compte() : Compte("null", 0.0) {}

Compte::Compte(const char *name, const double &balance)
        : m_ID(++Compte::s_nextID), m_balance(balance) {
    m_name = new char[strlen(name) + 1];
    strcpy(m_name, name);
}

Compte::~Compte() { delete[] m_name; }

void Compte::Print() const {
    std::cout << "ID: " << m_ID << ", Name: " << m_name
        << ", Balance: " << m_balance << std::endl;
}

void Compte::PrintBalance() const {
    std::cout << "Balance: " << m_balance << std::endl;
}

void Compte::Withdraw(const double &balance) {
    if (balance > m_balance) {
        std::cout << "Not enough balance" << std::endl;
        return;
    }
    if (balance < 0) {
        std::cout << "Invalid balance" << std::endl;
        return;
    }
    m_balance -= balance;
}

void Compte::Deposit(const double &balance) {
    if (balance < 0) {
        std::cout << "Invalid balance" << std::endl;
        return;
    }
    m_balance += balance;
}
