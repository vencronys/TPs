#include "Personne.h"
#include <cstring>
#include <iostream>

Personne::Personne() : Personne("null", "null", 0) {
}

Personne::Personne(const char *firstname, const char *lastname, const int &age) {
    this->m_firstname = new char[strlen(firstname) + 1];
    strcpy(this->m_firstname, firstname);
    this->m_lastname = new char[strlen(lastname) + 1];
    strcpy(this->m_lastname, lastname);
    this->m_age = age;
}

Personne::~Personne() {
    delete[] this->m_firstname;
    delete[] this->m_lastname;
}

void Personne::Display() const {
    std::cout << "Firstname: " << this->m_firstname << std::endl;
    std::cout << "Lastname: " << this->m_lastname << std::endl;
    std::cout << "Age: " << this->m_age << std::endl;
}
