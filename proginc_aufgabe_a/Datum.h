#ifndef PROGINC_AUFGABE_A_DATUM_H
#define PROGINC_AUFGABE_A_DATUM_H

// Samstag = 0; Sonntag = 1; Montag->Freitag: 2->6;
typedef enum { Samstag, Sonntag, Montag, Dienstag,
    Mittwoch, Donnerstag, Freitag} wochentag;

// 0 = "Samstag", 1 =  "Sonntag", etc.
const char* wochentage[];

// Tag, Monat, Jahr
typedef struct {
    unsigned int d, m, y;
} datum;

// Berechnet den Wochentag (0-6) eines Datums
wochentag berechne_wochentag(datum t);

// Liefert für (Tag, Monat, Jahr) ein Datum struct zurück
datum erzeuge_datum(unsigned int d, unsigned int m, unsigned int y);

#endif //PROGINC_AUFGABE_A_DATUM_H
