#pragma once

#define NEW_LINE '\n'

class Matrice {
private:
    char *nom;
    float **mat;
    int nl, nc;
public:
    Matrice(const char*, int = 3, int = 3, int = 0.0f);
    Matrice(const Matrice&);
    ~Matrice();
    void lecture(float ** ,const int&, const int&);
    void afficher() const;
    Matrice *transposee();
};
