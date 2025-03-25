#pragma once
#define NEW_LINE '\n'

class Mesure {
private:
    int mesure;
    static const int MIN;
    static const int MAX;
    static int nb_mesures;
    static int som_mesures;
public:
    Mesure(const int&);
    static void afficher_moyenne();
};
