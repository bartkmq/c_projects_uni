#ifndef PROGINC_AUFGABE_B_AREA_H
#define PROGINC_AUFGABE_B_AREA_H

// array mit Leerzeichen initialisieren
void initArea (int len, char (*area)[len]);

/* array mit Rand auf der Konsole ausgeben:
 * +---+
 * |123|
 * |456|
 * |789|
 * +---+
 * (len = 3, area = {{1,2,3},{4,5,6},{7,8,9}})
 */
void showArea (int len, char (*area)[len]);

#endif //PROGINC_AUFGABE_B_AREA_H
