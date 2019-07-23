#include "area.h"
#include <stdio.h>

void initArea (int len, char (*area)[len]) {
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            area[i][j] = ' ';
        }
    }
}

void showArea (int len, char (*area)[len]) {
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
                putchar(area[i][j]);
        }
        putchar('\n');
    }

    // lower border
    putchar('+');
    for (int i = 0; i < len; i++) putchar('-');
    putchar('+');
    putchar('\n');
}
