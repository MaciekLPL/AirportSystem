#include <iostream>

class A {

public:
    virtual void funkcja() {}

};


class B : public A {};

class C : public A {};

class D : public A {};


void wypisz_rodzaj(A* Obiekt) {

    if (dynamic_cast<B*>(Obiekt))
        std::cout << "Wskaznik na obiekt klasy B" << std::endl;

    else if (dynamic_cast<C*>(Obiekt))
        std::cout << "Wskaznik na obiekt klasy C" << std::endl;

    else if (dynamic_cast<D*>(Obiekt))
        std::cout << "Wskaznik na obiekt klasy D" << std::endl;

    else 
        std::cout << "Error" << std::endl;
}

int main() {

    A* objA1 = new B();
    wypisz_rodzaj(objA1);

    A* objA2 = new C();
    wypisz_rodzaj(objA2);

    A* objA3 = new D();
    wypisz_rodzaj(objA3);

}

