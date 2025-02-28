#include "Banque.h"

int main(int argc, char *argv[]) {
    Compte compte;
    compte.InitilizeCompte(123, "John Doe", 1000);
    compte.Consulter();
    compte.Deposer(500);
    compte.Consulter();
    compte.Retirer(200);
    compte.Consulter();

    Compte c1, c2;
    c1.InitilizeCompte(1, "Nig", 69);
    c2.InitilizeCompte(2, "Dante", 420);

    Banque banque;
    banque.Add(compte);
    banque.Add(c1);
    banque.Add(c2);
    banque.ShowComptes();
    banque.Delete(123);
    banque.ShowComptes();
    banque.GetCompte(2).Consulter();
    return 0;
}

