#include <stdio.h>
#include <math.h>
#include "Datum.h"

const char* wochentage[] = {"Samstag", "Sonntag", "Montag ", "Dienstag",
                            "Mittwoch", "Donnerstag", "Freitag"};

datum erzeuge_datum(unsigned int d, unsigned int m, unsigned int y) {
    if (d < 1 || d > 31 || m < 1 || m > 12 || y < 0 || y > 9999)
        printf("UNGÜLTIGES DATUM FEHLER\n");

    datum t_neu = { d, m, y };
    return t_neu;
}

wochentag berechne_wochentag(datum t) {
    unsigned int h_greg;

    // Januar/Februar entspricht dem 13./14. Monat des Vorjahres
    switch (t.m) {
        case 1:
            t.m = 13;
            t.y--;
            break;
        case 2:
            t.m = 14;
            t.y--;
            break;
        default: ;
    }

    unsigned int j; // die ersten beiden Stellen der Jahreszahl
    unsigned int k; // die letzten beiden Stellen der Jahreszahl
    j = t.y / 100; // 2016 / 100 = 20
    k = t.y - 100 * j; // 2016 - 20 * 100 = 16

    // Zellers Kongruenz
    h_greg = (unsigned int)(t.d + floor((t.m + 1 ) * 13 / 5) * k +
                            floor(k / 4) + floor(j / 4) + 5 * j) % 7;
    return (wochentag)h_greg;
}
