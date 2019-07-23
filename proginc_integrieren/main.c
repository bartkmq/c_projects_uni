#include <stdio.h>
#include <stdlib.h>

#include "integration.h"

int main() {
    double a, b;

    printf("Linke Intervallgrenze: ");
    scanf("%lf", &a);

    printf("Rechte Intervallgrenze: ");
    scanf("%lf", &b);

    printf("Anzahl der Teilintervalle: ");
    scanf("%d", &n);

    printf("Die Fläche unter dem Graphen beträgt: %f", integral(a, b));

    return 0;
}