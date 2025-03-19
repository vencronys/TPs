#include "Banque.h"
#include <iostream>

#define NEW_LINE '\n'

Banque::Banque(int capacity) {
    m_comptes = new Compte[capacity];
    m_size = 0;
    m_capacity = capacity;
}

Banque::~Banque() { delete[] m_comptes; }

void Banque::AddCompte(const Compte &compte) {
    if (m_size == m_capacity) {
        std::cout << "Banque is full" << NEW_LINE;
        return;
    }
    m_comptes[m_size++] = compte;
}

void Banque::RemoveCompte(const int &ID) {
    for (int i = 0; i < m_size; ++i) {
        if (m_comptes[i].GetID() == ID) {
            for (int j = i; j < m_size - 1; ++j) {
                m_comptes[j] = m_comptes[j + 1];
            }
            --m_size;
            return;
        }
    }
    std::cout << "Compte not found" << NEW_LINE;
}

void Banque::PrintComptes() const {
    for (int i = 0; i < m_size; ++i) {
        m_comptes[i].Print();
    }
}
