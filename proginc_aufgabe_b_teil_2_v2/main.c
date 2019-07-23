#include <stdio.h>
#include "area.h"
#include "ameise.h"

int main() {
    // Nach der Länge der Seite und max. Anzahl der Simulationsschritte fragen,
    int len;
    unsigned long max_schritte;
    printf("Bitte geben sie die Seitenlänge des quadratischen Rasters ein: ");
    scanf("%d", &len);
    printf("Geben sie die maximale Anzahl an Simulationsschritten ein: ");
    scanf("%lu", &max_schritte);

    // lokales Ameisen Objekt erzeugen und mit Blickrichtung nach unten in die
    // Mitte des Rasters setzten
    Ameise ameise = {len / 2, len / 2, 2}; // unten -> 2

    // Raster (array) mit der Seitenlänge len erzeugen
    char raster[len][len];
    // Raster mit Leerzeichen initialisieren
    initArea(len, raster);

    // Simulieren bis die Ameise das Raster verlässt oder die max. Anzahl an
    // Simulationsschritten erreicht ist
    while (max_schritte-- > 0 && nextStep(&ameise, len, raster));

    // Das Raster ausgeben
    showArea(len, raster);
}