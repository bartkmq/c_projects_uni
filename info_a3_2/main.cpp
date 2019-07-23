#include <iostream>

using namespace std;

int main () {
    int a[20] = {238, 18760, 14704, 19802, 25766, 25878, 4729, 14634, 18361, 9880, 29451, 30831, 30265, 10345, 20195, 9538, 492, 21769, 18197, 31417};
    int sum;
    int ctr;

    int n = 20;

    sum = ctr = 0;
    // einmal durch alle werte gehen
    for(int i = 0; i < n; i++) {
        // rest von a[i] / 17 zu der summe addieren
        sum += a[i] % 17;
        // wenn es beim teilen durch 4 einen Rest gibt ist  a[i] nicht durch 4 teilbar
        if ((a[i] % 4) != 0)
            ctr++;
    }

    cout << "Summe der Reste: " << sum << endl;
    cout << "Anzahl der Zahlen, die kein Vielfaches von 4 sind: ";
    cout << ctr << endl;

    return 0;
}