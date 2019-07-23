#include <math.h>
#include <cstdio>

double heron(double in) {
    double x = (in + 1) / 2;
    double tmp;
    do {
        tmp = x;
        x = (x + (in / x)) / 2;
    } while (fabs(x - tmp) >= 1e-5);
    return x;
}

double heron2_rec(double, double);
double heron2(double in) {
    return heron2_rec(in, (in + 1) / 2);
}

double heron2_rec(double in, double x) {
    double tmp = x;
    x = (x + (in / x)) / 2;
    if (fabs(x - tmp) >= 1e-5)
        return heron2_rec(in, x);
    else
        return x;
}

int main() {
    double in;
    printf("Zahl eingeben: ");
    scanf("%lf", &in);

    printf("Eingabe: %f\nHeron: %f\nSqrt: %f\n", in, heron2(in), sqrt(in));
    return 0;
}