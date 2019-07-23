#include <stdio.h>

typedef struct Ameise {
    int x, y;
    int blick; // 0 -> oben, 1 -> rechts, 2 -> unten, 3 -> links
} Ameise;

int nextStep(struct Ameise *am, int len, char feld[len]) {
    int pos = am->x * len + am->y;
    if (feld[pos] == '#') {
        feld[pos] = ' ';
        am->blick = (am->blick > 0) ? am->blick - 1 : 3;
    }
    else { // weiß
        feld[pos] = '#';
        am->blick = (am->blick < 3) ? am->blick + 1 : 0;
    }
    switch(am->blick) {
        case 0: // oben
            am->y--;
            return am->y >= 0;
        case 1: // rechts
            am->x++;
            return am->x < (len - 1);
        case 2: // unten
            am->y++;
            return am->y < (len - 1);
        case 3: // links
            am->x--;
            return am->x >= 0;
        default:
            printf("ERROR!\n");
            return 0;
    }
}

void showArea (int len, char area[len]) {
    // upper border
    putchar('+');
    for (int i = 0; i < len; i++) putchar('-');
    putchar('+');
    putchar('\n');

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len + 1; j++) {
            if (j == 0 || j == len)
                putchar('|');
            if (j < len)
                putchar(area[j * len + i]);
        }
        putchar('\n');
    }

    // lower border
    putchar('+');
    for (int i = 0; i < len; i++) putchar('-');
    putchar('+');
    putchar('\n');
}

int main() {
    int len;
    unsigned long maxSteps;
    printf("Bitte Größe des quadratischen Rasters eingeben.\n");
    printf("Länge der Seiten: ");
    scanf("%d", &len);
    printf("Maximale Anzahl an Schritten: ");
    scanf("%lu", &maxSteps);

    Ameise ameise = {len / 2, len / 2, 2};
    char feld[len * len];
    for (int i = 0; i < len * len; i++) {
        feld[i] = ' ';
    }

    while (maxSteps-- != 0 && nextStep(&ameise, len, feld));

    showArea(len, feld);

    return 0;
}