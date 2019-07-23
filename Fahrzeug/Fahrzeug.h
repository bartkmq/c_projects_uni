#ifndef FAHRZEUG_FAHRZEUG_H
#define FAHRZEUG_FAHRZEUG_H

class Fahrzeug {
public:
    Fahrzeug();
    Fahrzeug(int hubraum, int leistung, const char* farbe, int anzahl_raeder,
             float zustand);

    void ausgeben();
    void tunen();
    void fahren(long);
protected:
    int hubraum; // in cm^3
    int leistung; // in kW
    const char *farbe;
    int anzahl_raeder;
    float zustand; // in %
};


#endif //FAHRZEUG_FAHRZEUG_H
