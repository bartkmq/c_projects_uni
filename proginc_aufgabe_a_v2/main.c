#include <stdio.h>
#include "Datum.h"

int main() {

    // Die Anzahl der einzelnen Wochentagen an 13. in 400 Jahren berechnen
    unsigned int haeufigkeit_wochentage[7] = {};
    for (unsigned int jahr = 2000; jahr < 2400; jahr++) {
        for (unsigned int monat = 1; monat <= 12; monat++) {
            haeufigkeit_wochentage[h_greg(13, monat, jahr)]++;
        }
    }

    // Liste mit Zuordnung Wochentag->Häufigkeit ausgeben und
    // größte Häufigkeit ermitteln
    unsigned int groesste_haeufigkeit = 0;
    printf("Wochentag \t | Häufigkeit\n");
    for (unsigned int i = 0; i < 7; i++) {
        printf("%s \t | %d\n", monats_namen[i], haeufigkeit_wochentage[i]);
        if (haeufigkeit_wochentage[i] > groesste_haeufigkeit)
            groesste_haeufigkeit = haeufigkeit_wochentage[i];
    }

    // Alle Wochentage mit der größten Häufigkeit ausgeben
    printf("\nDie folgenden Wochentage haben die größte Häufigkeit:\n");
    for (unsigned int i = 0; i < 7; i++) {
        if (haeufigkeit_wochentage[i] == groesste_haeufigkeit)
            printf("%s\n", monats_namen[i]);
    }

    // Den Wochentag an einem bestimmten Datum ausrechnen
    printf("\nWochentag am 13.Dezember.2016: %s\n", monats_namen[h_greg(13, 12, 2016)]);

    return 0;
}