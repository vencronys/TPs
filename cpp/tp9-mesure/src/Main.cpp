#include <iostream>
#include "Mesure.h"


int main(int argv, char** argc) {
    int nb_mesures;
    Mesure **mesures;
    std::cout << "Entrez le nombre de mesures: ";
    std::cin >> nb_mesures;
    mesures = new Mesure* [nb_mesures];
    for (int i = 0, mesure; i < nb_mesures; i++) {
        std::cout << "Entrez une mesure: ";
        std::cin >> mesure;
        mesures[i] = new Mesure(mesure);
    }
    Mesure::afficher_moyenne();
    return 0;
}
