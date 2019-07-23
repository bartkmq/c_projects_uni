#include <iostream>
# include <cmath>
using namespace std;

double geom(int laenge, double a[]) {
    double prod = 1;
    for (int i = 0; i < laenge; i++) {
        if (a[i] < 0)
            return 0;
        prod *= a[i];
    }
    return pow(prod, 1.0f / laenge);
}

int main () {
    const int anzahl = 12;
    double a[ anzahl ] = {13.2 , 31.67 ,81.22 ,25.51 ,91.78 ,35.99 ,75.17 ,44.0 ,68.5 ,16.5 ,39.1 ,31.45};
    cout <<  "Das geometrische Mittel: " << geom(12, a) << endl;
    /*
     * [Ausgabe:] Das geometrische Mittel: 39.1967
     */
    return 0;
}