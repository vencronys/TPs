#include "Compte.h"
#include <cstring>
#include <iostream>

#define NEW_LINE '\n'

int Compte::s_nextID = 0;

Compte::Compte(const char *name, const double &balance)
    : m_ID(++Compte::s_nextID), m_balance(balance) {
  m_name = new char[strlen(name) + 1];
  strncpy(m_name, name, strlen(name));
  m_name[strlen(name)] = '\0';
}

Compte::Compte(const Compte &compte)
    : m_ID(++Compte::s_nextID), m_balance(compte.m_balance) {
  m_name = new char[strlen(compte.m_name) + 1];
  strncpy(m_name, compte.m_name, strlen(compte.m_name));
  m_name[strlen(compte.m_name)] = '\0';
}

Compte::~Compte() { delete[] m_name; }

void Compte::Print() const {
  std::cout << "ID: " << m_ID << ", Name: " << m_name
            << ", Balance: " << m_balance << NEW_LINE;
}

void Compte::PrintBalance() const {
  std::cout << "Balance: " << m_balance << NEW_LINE;
}

void Compte::Withdraw(const double &balance) {
  if (balance > m_balance) {
    std::cout << "Not enough balance" << NEW_LINE;
    return;
  }
  if (balance < 0) {
    std::cout << "Invalid balance" << NEW_LINE;
    return;
  }
  m_balance -= balance;
}

void Compte::Deposit(const double &balance) {
  if (balance < 0) {
    std::cout << "Invalid balance" << NEW_LINE;
    return;
  }
  m_balance += balance;
}
