#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "tipputils.h"

// größer als: zeile + \0 + \n
#define MAX_LINE_SIZE 80

// storage dir for output files
#define STORAGE_PATH "/home/marco/"

int main() {
    FILE *fp;
    char line[MAX_LINE_SIZE + 10];

    unlink(STORAGE_PATH"list_3_correct.txt");
    unlink(STORAGE_PATH"list_4_correct.txt");
    FILE *fp_list_3 = fopen(STORAGE_PATH"list_3_correct.txt", "w");
    FILE *fp_list_4 = fopen(STORAGE_PATH"list_4_correct.txt", "w");

    char path[2048] = {0};
    printf("Bitte Pfad eingeben: ");
    fgets(path, 2000, stdin);

    printf("Pfad: %s", path);

    int win_numbers[6] = {0};
    printf("Bitte die 6 Gewinnzahlen eingeben:\n");
    for (int i = 0; i < 6; i++) {
        scanf("%d", &win_numbers[i]);
    }

    // replace \n with \0
    for (int i = 0; path[i] != '\0'; i++) {
        if (path[i] == '\n')
            path[i] = '\0';
    }

    fp = fopen(path, "r");
    if (fp == NULL || ferror(fp)) printf("FILE_ERROR_LOAD\n");

    int n_tipps = 0, n_valid = 0;
    int n_3_correct = 0, n_4_correct = 0, n_5_6_correct = 0;

    while (fgets(line, MAX_LINE_SIZE, fp) != NULL) {
        if (ferror(fp)) printf("FILE_ERROR_LOOP\n");

        char nr[10] = {0}; // 7B schein_nr + 1B Leerzeichen + 1B Tipp_nr + \0
        int n_kreuze = 0; // Anzahl der Kreuze auf dem Schein
        int kreuze[49] = {0}; // die getippten nummern
        tippAuswerten(line, nr, &n_kreuze, kreuze);

        n_tipps++;
        if (n_kreuze <= 6)
            n_valid++;
        else
            continue;

        // Anzahl der richtig getippten Nummern
        int n_correct = 0;
        for (int i = 0; i < 49; i++) {
            for (int j = 0; j < 6; j++) {
                if (kreuze[i] == win_numbers[j]) {
                    n_correct++;
                }
            }
        }
        switch(n_correct) {
            case 3:
                n_3_correct++;
                fputs(nr, fp_list_3);
                fputc('\n', fp_list_3);
                break;
            case 4:
                n_4_correct++;
                fputs(nr, fp_list_4);
                fputc('\n', fp_list_4);
                break;
            case 5: case 6: n_5_6_correct++; break;
        }
    }
    printf("Anzahl der Tipps: %d\n", n_tipps);
    printf("Anzahl der gültigen Tipps: %d\n", n_valid);
    printf("Anzahl der Tipps mit 3 Richtigen: %d\n", n_3_correct);
    printf("Anzahl der Tipps mit 4 Richtigen: %d\n", n_4_correct);
    printf("Anzahl der Tipps mit 5 oder 6 Richtigen: %d\n", n_5_6_correct);

    fclose(fp);
    fclose(fp_list_3);
    fclose(fp_list_4);
    return 0;
}