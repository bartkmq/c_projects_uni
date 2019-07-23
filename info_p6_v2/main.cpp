#include <iostream>
#include "Vektor.h"

using namespace std;

Vektor<float> calc_norm_vektor(Vektor<float> a, Vektor<float> b) {
    return (a * b).normalize();
}

int main() {
    Vektor<float> v1 = Vektor<float>(0, 0, 1);
    Vektor<float> v2 = Vektor<float>(0, 2, 0);

    Vektor<float> norm = calc_norm_vektor(v1, v2);
    norm.print(1);

    (v1 * v2).print(1);
    cout << "Skalarprodukt: " << v1.dot(v2) << endl;

    return 0;
}