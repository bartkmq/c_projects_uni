#include <math.h>

unsigned int n;

double func(double x) {
    return exp(-pow(x, 2));
}

double integral(double a, double b) {
    double result = 0;
    double intervall_size = fabs(a - b) / n;
    for(int i = 0; i < n; i++) {
        result += func(i * intervall_size + intervall_size / 2) * intervall_size;
    }
    return result;
}