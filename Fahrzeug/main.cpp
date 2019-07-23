#include <iostream>
#include "Fahrzeug.h"

int main() {
    /**
     * (1) Fahrzeuginstanz mit Default-Konstruktor testen.
     */
    Fahrzeug f1 = Fahrzeug();
    f1.ausgeben();

    f1.tunen();
    f1.ausgeben();

    f1.fahren(10000);
    f1.ausgeben();

    std::cout << std::endl;

    /**
     * (2) Fahrzeug mit Konstruktor mit Parametern testen.
     */
    Fahrzeug f2 = Fahrzeug(100, 1000, "rot", 3, 50);
    f2.ausgeben();
    f2.tunen();
    f2.tunen();
    f2.ausgeben();
    f2.fahren(3E6);
    f2.ausgeben();

    std::cout << std::endl;

    /**
     * (3) Fehlerhafte Werte als Argumente testen.
     */
     Fahrzeug f3 = Fahrzeug(-5, 0, nullptr, 0, -50.7);
    f3.ausgeben();
}