#include "Datum.h"

char *monats_namen[7] = {"Samstag", "Sonntag", "Montag ", "Dienstag",
                         "Mittwoch", "Donnerstag", "Freitag"};

unsigned int h_greg(unsigned int t, unsigned int m, unsigned int jahr) {
    // Wenn der Monat Januar oder Februar ist muss 13/14 anstatt 1/2
    // für m verwendet werden und das Jahr muss um eins verringert werden
    if (m == 1 || m == 2) {
        m += 12;
        jahr--;
    }

    unsigned int j; // Jahrhunderzahl
    unsigned int k; // die letzten beiden Stellen der vierzahligen Jahreszahl
    j = jahr / 100;
    k = jahr - j * 100;

    // Zellers Kongruenz berechnen
    return (unsigned int)(t + floor((m + 1) * 13 / 5.0f) + k + floor(k / 4.0f)
                          + floor(j / 4.0f) + 5 * j) % 7;

}

