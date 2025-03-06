#include "Personne.h"
#include <cstring>
#include <iostream>

Personne::Personne() : Personne("null", "null", 0) {
}

Personne::Personne(const char *firstname, const char *lastname, const int &age) {
    m_firstname = new char[strlen(firstname) + 1];
    strcpy(m_firstname, firstname);
    m_lastname = new char[strlen(lastname) + 1];
    strcpy(m_lastname, lastname);
    m_age = age;
}

Personne::~Personne() {
    delete[] m_firstname;
    delete[] m_lastname;
}

void Personne::Display() const {
    std::cout << "Firstname: " << m_firstname << std::endl;
    std::cout << "Lastname: " << m_lastname << std::endl;
    std::cout << "Age: " << m_age << std::endl;
}
