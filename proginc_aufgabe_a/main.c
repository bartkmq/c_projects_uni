#include <stdio.h>
#include "Datum.h"

int main() {
    datum t = erzeuge_datum(13, 1, 2000);
    // Treffer ^= ein 13. Tag hat an diesem Wochentag stattgefunden
    unsigned int treffer_pro_wochentag[7] = {};

    for (unsigned int y = 2000; y <= 2400; y++) {
        t.y = y;
        for (unsigned int m = 1; m <= 12; m++) {
            t.m = m;
            unsigned int wochentag = berechne_wochentag(t);
            // Die Anzahl an Treffern für den entsprechenden Wochentag
            // um eins erhöhen
            treffer_pro_wochentag[wochentag]++;
        }
    }

    unsigned int n_treffer_max = 0; // höchste Anzahl an Treffern pro Wochentag

    // Liste mit einer Wochentag->Treffer-Zuordnung ausgeben
    printf("Wochentag | Treffer\n");
    for (unsigned int i = 0; i < 7; i++) {
        unsigned int treffer = treffer_pro_wochentag[i];
        printf("%s \t %d\n", wochentage[i], treffer);
        // höchste Anzahl an Treffern finden
        if (treffer > n_treffer_max)
            n_treffer_max = treffer;
    }

    // Wochentage mit der höchsten Anzahl an Treffern ausgeben
    printf("\nDer 13. ist am häufigsten einer der folgenden Wochentage:\n");
    for (unsigned int i = 0; i < 7; i++) {
        if (treffer_pro_wochentag[i] == n_treffer_max)
            printf("%s (%d)\n", wochentage[i], n_treffer_max);
    }

    return 0;
}