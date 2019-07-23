#include <string.h>
#include "tipputils.h"

void tippAuswerten(const char* zeile, char* snrTnr,
                   int* anzahlKreuze, int kreuze[]) {
    memcpy(snrTnr, zeile, 9);
    *anzahlKreuze = 0;
    for (int i = 10; i < 59; i++) {
        if (zeile[i] == 'X') {
            kreuze[*anzahlKreuze] = i + 1 - 10;
            (*anzahlKreuze)++;
        }
    }
}

