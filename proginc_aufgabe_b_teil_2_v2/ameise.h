#ifndef PROGINC_AUFGABE_B_TEIL_2_V2_AMEISE_H
#define PROGINC_AUFGABE_B_TEIL_2_V2_AMEISE_H

// Daten die den Zustand einer Ameise beschreiben
typedef struct Ameise {
    // Position der Ameise
    int x, y;
    // Blickrichtung der Ameise
    char blick; // 0 -> oben, 1 -> rechts, 2 -> unten, 3 -> links
} Ameise;

// Einen Schritt der Ameise simulieren
int nextStep(Ameise *am, int len, char (*raster)[len]);

#endif //PROGINC_AUFGABE_B_TEIL_2_V2_AMEISE_H
