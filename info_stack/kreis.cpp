#include "kreis.h"

Kreis::Kreis() : Kreis::Kreis(0, 0, 1) {}

Kreis::Kreis(double p_x, double p_y, double p_r) {
    set_x(p_x);
    set_y(p_y);
    set_r(p_r);
}

double Kreis::umfang() {
    return r * 2 * M_PI;
}

double Kreis::flaeche() {
    return r * r * M_PI;
}

bool Kreis::liegtInnerhalb(double p_x, double p_y) {
    double dx = abs(p_x - x);
    double dy = abs(p_y - y);
    return dx * dx + dy * dy <= r * r;
}