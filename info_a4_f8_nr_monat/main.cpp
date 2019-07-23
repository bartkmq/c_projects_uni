#include <iostream>
using namespace std;

int main () {
    int monat;
    char schaltjahr;

    cout << " Bitte geben Sie die Nummer des Monats ein " << endl;
    cout << "1- Januar , 2- Februar , ... , 12- Dezember " << endl;

    /* START */

    unsigned int monate_laenge[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    cin >> monat;

    if (monat <= 0 || monat > 12) {
        cout << "Die Nummer des Monats sollte zwischen 1 und 12 liegen" << endl;
        cout << "Zum Beispiel: 1- Januar , 2- Februar , ... , 12- Dezember " << endl;
        return 1;
    }

    unsigned int tage = monate_laenge[monat - 1];

    if (monat == 2) {
        cout << "Handelt es sich um ein Schaltjahr?" << endl;
        cout << "Bitte Ja (j) oder Nein (n) eingeben: ";

        cin >> schaltjahr;

        switch (schaltjahr) {
            case 'j': case 'J':
                tage++;
                break;
            case 'n': case 'N':
                break;
            default:
                cout << "Fehlerhafte Eingabe!" << endl;
                return 1;
        }
    }

    cout << "Dieser Monat hat " << tage << " Tage." << endl;

    /* END */

    return 0;
}