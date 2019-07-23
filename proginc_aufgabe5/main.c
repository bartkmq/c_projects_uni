#include <stdio.h>
#include <math.h>

int main() {
    FILE *f_1 = fopen("/home/marco/ClionProjects/proginc_aufgabe5/assets/teil_1.txt", "r");
    FILE *f_2 = fopen("/home/marco/ClionProjects/proginc_aufgabe5/assets/teil_2.txt", "r");
    FILE *f_result = fopen("/home/marco/ClionProjects/proginc_aufgabe5/assets/result.html", "w");

    if (f_1 == 0 || f_2 == 0) {
        printf("Dateifehler!");
    }

    char c;
    int alternate = 0;
    unsigned int n_c = 0, n_endl = 0;

    while (!(alternate && c == EOF)) {
        c = (alternate) ? fgetc(f_1) : fgetc(f_2);
        if (c != EOF) {
            fputc(c, f_result);
            n_c++;
        }
        if (c == '\n')
            n_endl++;
        alternate = 1 - alternate;
    }

    printf("Anzahl an Zeichen: %d\n", n_c);
    printf("Anzahl an Zeilenumbrüchen: %d\n", n_endl);

    fclose(f_1);
    fclose(f_2);
    fclose(f_result);

    return 0;
}