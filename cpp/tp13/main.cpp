#include "Commercial.h"
#include "Manutentionnaire.h"
#include "Representant.h"
#include "Technicien.h"
#include "Vendeur.h"
#include <iostream>

int main() {
    Commercial c1("IDRISSI", "Youness", 22, 3, 10000);
    Manutentionnaire m1("ESSOUFI", "Doha", 22, 7, 40);
    Technicien t1("EL AISSAOUI", "ILIASS", 23, 2, 100);
    c1.afficher();
    t1.afficher();
    m1.afficher();
    std::cout << "Salaire Commercial c1: " << c1.calculer_salaire() << "\n";
    std::cout << "Salaire Technicien t1: " << t1.calculer_salaire() << "\n";
    std::cout << "Salaire Manutentionnaire m1: " << m1.calculer_salaire()
              << "\n";

    std::cout << "******************\n";

    Vendeur v1("ELKADIRI", "Saad", 22, 3, 10000);
    v1.afficher();
    std::cout << "Salaire Vendeur v1: " << v1.calculer_salaire() << "\n";

    std::cout << "******************\n";

    Representant r1("ELHADDI", "Yassine", 22, 3, 10000.00, 40);
    r1.afficher();

    return 0;
}
