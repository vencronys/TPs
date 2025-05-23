#include <iostream>

class A {
  protected:
    int i;

  public:
    A(int k) {
        i = k;
        std::cout << "Constructeur A " << i << '\n';
    }
    virtual ~A() { std::cout << "Destructeur A\n"; }
    virtual void affiche() { std::cout << "i = " << i << '\n'; }
};

class B : public A {
  private:
    int j;

  public:
    B(int k, int n = 1) : A(k) {
        j = n;
        std::cout << "Constructeur B " << j << '\n';
    };
    virtual ~B() { std::cout << "Destructeur B\n"; }
    virtual void affiche() {
        A::affiche();
        std::cout << "j = " << j << '\n';
    }
};

void afficheA(A *);
// void afficheB(B *);

int main() {
    // A a(1);
    // B b(2);
    A *a, *b;
    a = new A(10);
    b = new B(20, 30);
    afficheA(a);
    afficheA(b);
    delete a;
    delete b;
    return 0;
}

void afficheA(A *t) { t->affiche(); }
// void afficheB(A *t) { t->affiche(); }