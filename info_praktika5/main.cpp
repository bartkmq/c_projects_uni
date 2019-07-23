#include <iostream>

using namespace std;

void printvars(char teilaufgabe, int i, int j, int *p, int *q) {
    cout << "--- Ausgabe nach Teilaufgabe " << teilaufgabe << ") ---" << endl;

    cout << "\t\t\t" << "Adresse\t\t\t" << "Inhalt\t\t\t\t"
         << "referenzierter Wert" << endl;

    cout << "Variable i\t" << &i << "\t" << i << endl;
    cout << "Variable j\t" << &j << "\t" << j << endl;
    cout << endl;
    cout << "Variable p\t" << &p << "\t" << p << "\t\t" << *p << endl;
    cout << "Variable q\t" << &q << "\t" << q << "\t\t" << *q << endl;
    cout << endl;
}

int main() {
    int i = 40;
    int j = 21;

    int *p = &i;
    int *q = &j;
    printvars('a', i, j, p, q);

    int *tmp = p;
    p = q;
    q = tmp;
    printvars('b', i, j, p, q);

    // TODO: Papier und Stift ...

    *q += 2;
    printvars('d', i, j, p, q);
}