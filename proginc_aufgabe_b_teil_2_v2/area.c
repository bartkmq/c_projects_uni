#include "area.h"
#include <stdio.h>

// array mit Leerzeichen initialisieren
void initArea (int len, char (*area)[len]) {
    // durch das komplette array gehen und jedes Element gleich ' ' setzten
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            area[i][j] = ' ';
        }
    }
}

/* array mit Rand auf der Konsole ausgeben:
 * +---+
 * |123|
 * |456|
 * |789|
 * +---+
 * (len = 3, area = {{1,2,3},{4,5,6},{7,8,9}})
 */
void showArea (int len, char (*area)[len]) {
    // oberer Rand
    putchar('+');
    for (int i = 0; i < len; i++) putchar('-');
    putchar('+');
    putchar('\n');

    for (int i = 0; i < len; i++) { // für alle zeilen des arrays ...
        putchar('|'); // linker Rand
        for (int j = 0; j < len; j++) { // aktuelle zeile des arrays ausgeben
            putchar(area[i][j]);
        }
        putchar('|'); // rechter Rand
        putchar('\n');
    }

    // unterer Rand
    putchar('+');
    for (int i = 0; i < len; i++) putchar('-');
    putchar('+');
    putchar('\n');
}