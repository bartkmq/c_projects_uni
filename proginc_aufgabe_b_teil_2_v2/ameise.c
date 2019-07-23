#include "ameise.h"

// Einen Schritt der Ameise simulieren
int nextStep(Ameise *am, int len, char (*raster)[len]) {
    if (raster[am->y][am->x] == ' ') { // Wenn das Feld weiß ist ...
        raster[am->y][am->x] = '#'; // es schwarz färben
        // und nach rechts drehen
        am->blick++;
        // blick muss beim erreichen von Links(3) nach Oben(0) "überlaufen"
        if (am->blick > 3) am->blick = 0;
    }
    else { // oder wenn es schwarz ist ...
        raster[am->y][am->x] = ' '; // es weiß färben
        // und nach links drehen
        am->blick--;
        // blick muss beim erreichen von Oben(0) nach Links(3) "unterlaufen"
        if (am->blick < 0) am->blick = 3;
    }
    // Positionsdelta je nach Blickrichtung
    int richtung_delta[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
    // Ein Schritt in die aktuelle Blickrichtung gehen
    am->x += richtung_delta[am->blick][0];
    am->y += richtung_delta[am->blick][1];
    // Wenn die neue Position noch im Raster ist, wahr zurückliefern
    return am->x >= 0 && am->x < len && am->y >= 0 && am->y < len;
}
