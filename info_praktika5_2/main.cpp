//-----------------------------------------------
// Rahmenprogramm zu Blatt 5, Aufgabe 2
//-----------------------------------------------

#include <iostream>
using namespace std;


void PascalschesDreieck(int **pascal, int n)
{
    // TODO: Code zur Berechnung des Dreiecks hier einfuegen (2 Punkte)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i)
                pascal[j][i] = 1;
            else
                pascal[j][i] = pascal[j - 1][i - 1] + pascal[j][i - 1];
        }
    }
}


int main()
{
    int n = 0;
    int **pascal;

    // TODO: Code zur Eingabe der Anzahl zu berechnender Zeilen hier einfuegen (1 Punkt)
    cout << "Bitte geben sie die Anzahl der Zeilen des Dreiecks ein: ";
    cin >> n;

    // TODO: Code zur Reservierung des Speichers hier einfuegen (2 Punkte)
    pascal = new int*[n];
    for (int i = 0; i < n; i++) {
        pascal[i] = new int[i + 1];
    }

    // Berechnung des Dreiecks
    PascalschesDreieck(pascal,n);


    // TODO Code zur Ausgabe des Dreiecks hier einfuegen (2 Punkte)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << pascal[j][i] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // TODO: Code zur Freigabe des Speichers hier einfuegen (1 Punkt)
    for (int i = 0; i < n; i++) {
        delete[] pascal[i];
    }
    delete[] pascal;

    cin >> n;


    return 0;
}