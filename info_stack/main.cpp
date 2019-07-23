#include <iostream>
#include "kreis.h"

using namespace std;

int main() {
    Kreis k1 {};
    Kreis k2 {1, 1, 2};

    cout << "Fläche von k1: " << k1.flaeche() << endl;
    cout << "Umfang von k1: " << k1.umfang() << endl;
    cout << endl;

    cout << "Fläche von k2: " << k2.flaeche() << endl;
    cout << "Umfang von k2: " << k2.umfang() << endl;
    cout << endl;

    k1.set_x(2);
    k1.set_y(2);
    cout << "Punkt(1.25, 1.25) liegt im Kreis?: " <<
         k1.liegtInnerhalb(1.25, 1.25) << endl;

    return 0;
}