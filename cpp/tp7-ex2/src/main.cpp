#include "Compte.h"

int main() {

    Compte c1("Alice", 100.0);
    c1.Print();
    c1.Deposit(-50.0);
    c1.PrintBalance();
    c1.Withdraw(200.0);
    c1.PrintBalance();
    c1.Withdraw(-50.0);

    Compte c2;
    c2.Print();

    return 0;
}
