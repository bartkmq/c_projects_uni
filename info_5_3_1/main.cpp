#include <iostream>

using namespace std;

// length str < 100

void invers(char str[]) {
    char copy[100] = {0};

    int i;
    for (i = 0; str[i] != '\0'; i++) {
        copy[i] = str[i];
    }
    // i = 8
    for (int j = 0; j < i - 1; j++) {
        str[i - 2 - j] = copy[j];
    }
}

char kleinbuch(char c) {
    // bitweise operatoren bei signed datentypen nicht definiert
    unsigned char uc = c;
    // das 5te Bit ist bei ascii kleinbuchstaben gleich 1
    return uc |= 1 << 5;
}

void umwandeln(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = kleinbuch(str[i]);
    }
}

int main () {

    // Aufruf Ihrer Funktionen und Ausgabe des Ergebnis
    char word[] = {'E', 'l', 'e', 'f', 'a', 'n', 't', '\0 '};

    cout << word << endl; // Elefant
    invers(word);
    cout << word << endl; // tnafelE

    cout << kleinbuch('C') << endl; // c

    invers(word);
    umwandeln(word);
    cout << word << endl; // elefant

    return 0;
}