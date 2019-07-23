#include <iostream>

using namespace std;

    int main () {
    double a[10] = {12.6, 33.77, 51.32, 95.11, 19.78, 635.34, 85.18, 89.0, 37.5, 24.1};
    double sum, quad;

    int n = 10;
    sum = 0;
    for(int i = 0; i < n; i++)
        sum += a[i] / (i + 1);

    quad = 0;
    for(int i = 0; i < n; i++)
        quad += a[i] * a[i];
    quad /= n;

    cout << "Gewichtete Summe: " << sum << endl;
    cout << "Quadrat des quadratischen Mittels: ";
    cout << quad << endl;

    return 0;
}