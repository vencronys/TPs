#include <iostream>
#include "Mesure.h"

const int Mesure::MIN = -100;
const int Mesure::MAX = 100;
int Mesure::nb_mesures = 0;
int Mesure::som_mesures = 0;

Mesure::Mesure(const int &mesure_) {
    if (mesure_ < Mesure::MIN) {
        std::cout << "ERROR: MESURE HORS INTERVALLE." << NEW_LINE
            << "La mesure ne doit pas etre dessous " << Mesure::MIN << "." << NEW_LINE
            << "DEFAULTING to 99999." << NEW_LINE;
        mesure = 99999;
        return;
    }
    if (mesure_ > Mesure::MAX) {
        std::cout << "ERROR: MESURE HORS INTERVALLE." << NEW_LINE
            << "La mesure ne doit pas depasser " << Mesure::MAX << "." << NEW_LINE
            << "DEFAULTING to 99999." << NEW_LINE;
        mesure = 99999;
        return;
    }
    mesure = mesure_;
    if (mesure_) {
        nb_mesures++;
        som_mesures += mesure;
    }
}

void Mesure::afficher_moyenne() {
    if (Mesure::nb_mesures == 0) {
        std::cout << "Zero mesures." << NEW_LINE;
        return;
    }
    std::cout << "La moyenne de " << Mesure::nb_mesures << " = "
        << Mesure::som_mesures / Mesure::nb_mesures << "." << NEW_LINE;
}
