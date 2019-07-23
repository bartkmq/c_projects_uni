#include <stdio.h>
#include <stdlib.h>

const float pi = acos(-1.0);

int main()
{
    float radius, flaeche;

    printf("Bitte geben sie den Radius ein: ");
    scanf("%f", &radius);
    flaeche = pi * radius * radius;
    printf("Der eingegebene Radius war: %lf\nDaraus folgt die Flaeche: %lf",
                radius, flaeche);

    return 0;
}
