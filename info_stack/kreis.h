#ifndef INFO_STACK_KREIS_H
#define INFO_STACK_KREIS_H

#include <iostream>
#include <cmath>

using namespace std;

class Kreis {
public:
    Kreis();
    Kreis(double p_x, double p_y, double p_r);

    double umfang();
    double flaeche();
    bool liegtInnerhalb(double p_x, double p_y);

    void set_x(double p_x) {
        if (p_x > 100) {
            p_x = 100;
            cout << "Fehler: Wert liegt nicht im gültigen Bereich!" << endl;
        }
        else if (p_x < -100) {
            p_x = -100;
            cout << "Fehler: Wert liegt nicht im gültigen Bereich!" << endl;
        }
        x = p_x;
    }
    double get_x() {
        return x;
    }

    void set_y(double p_y) {
        if (p_y > 100) {
            p_y = 100;
            cout << "Fehler: Wert liegt nicht im gültigen Bereich!" << endl;
        }
        else if (p_y < -100) {
            p_y = -100;
            cout << "Fehler: Wert liegt nicht im gültigen Bereich!" << endl;
        }
        y = p_y;
    }
    double get_y() {
        return y;
    }

    void set_r(double p_r) {
        if (p_r > 50) {
            p_r = 50;
            cout << "Fehler: Wert liegt nicht im gültigen Bereich!" << endl;
        }
        else if (p_r < 1) {
            p_r = 1;
            cout << "Fehler: Wert liegt nicht im gültigen Bereich!" << endl;
        }
        r = p_r;
    }
    double get_r() {
        return r;
    }

private:
    double x, y; // [-100;100] // sonst Fehlermeldung und ins Intervall setzen
    double r; // [1;50]
};


#endif //INFO_STACK_KREIS_H
