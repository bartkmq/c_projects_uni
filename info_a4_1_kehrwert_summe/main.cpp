#include <iostream>
using namespace std;

int main () {
    unsigned int m = 5;
    double sum = 0;
    long n;

    /* START */

    // m = 1 -> n = 2; sum = 1.5
    // m = 2 -> n = 4; sum = 2.0833

    n = 0;
    while(sum <= m) {
        sum += 1.0f / (n + 1);
        n++;
    }

    /* END */

    cout << "Man muss " << n <<" Zahlen aufsummieren ." << endl ;
    cout << "Die Summe ist " << sum << endl ;

    return 0;
}