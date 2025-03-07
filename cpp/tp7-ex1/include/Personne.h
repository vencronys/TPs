#pragma once
class Personne {

public:
    Personne();
    Personne(const char *firstname, const char *lastname, const int &age);
    ~Personne();
    void Print() const;

private:
    char *m_firstname;
    char *m_lastname;
    int m_age;

};
