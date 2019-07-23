#include <iostream>

using namespace std;

// length str < 100

int fakultaet(int in) {
    int fak = 1;
    while (in != 0)
        fak *= in--;
    return 0;
}

void invers(char str[]) {
    char copy[100] = {0};

    // eine Kopie des Eingabe Arrays erstellen
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        copy[i] = str[i];
    }

    // i = 8 bei "Elefant"
    // Kopie durchlaufen und von hinten in das Eingabearray schreiben
    // da das array als reference übergeben wird, wird auch das array außerhalb dieser Fn. verändert
    for (int j = 0; j < i; j++) {
        str[i - 1 - j] = copy[j];
    }
}

void kleinbuch(char str[]) {

}

void umwandeln() {

}

int main () {

    // Aufruf Ihrer Funktionen und Ausgabe des Ergebnis
    char word[] = {'E', 'l', 'e', 'f', 'a', 'n', 't', '\0'};

    cout << word << endl; // Elefant
    invers(word);
    cout << word << endl; // tnafelE

    return 0;
}