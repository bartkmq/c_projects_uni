#include <iostream>
#include "Fahrzeug.h"

using namespace std;

// Konstruktor ohne Paramter
Fahrzeug::Fahrzeug() : Fahrzeug::Fahrzeug(623, 26, "schwarz", 4, 100) {}

Fahrzeug::Fahrzeug(int hubraum, int leistung, const char* farbe,
                   int anzahl_raeder, float zustand) {
    /**
     * hubraum: Hubraum des Motors in ccm (sollte größer 0 sein)
     * leistung: Leistung des Motors in kW (sollte größer 0 sein)
     * farbe: Farbe des Fahrzeugs (sollte nicht null sein)
     * anzahl_raeder: Anzahl der Räder des Fahrzeugs (sollte größer 0 sein)
     * zustand: Zustand des Fahrzeugs (sollte im Bereich 0.0 ... 100.0 liegen)
     *
     * Wenn die Parameter nicht in einem sinnvollen Rahmen gewählt wurden,
     * werden sie durch Werte ersetzt die in diesem Rahmen liegen.
     */
    this->hubraum = (hubraum <= 0) ? 1 : hubraum;
    this->leistung = (leistung <= 0) ? 1 : leistung;
    this->farbe = (!farbe) ? "undefiniert" : farbe;
    this->anzahl_raeder = (anzahl_raeder <= 0) ? 1 : anzahl_raeder;
    if (zustand > 100) {
        this->zustand = 100;
    }
    else if (zustand < 0) {
        this->zustand = 0;
    }
    else {
        this->zustand = zustand;
    }
}

/**
 * Gibt die Daten des Fahrzeugs auf der Konsole aus.
 */
void Fahrzeug::ausgeben() {
    cout << "Fahrzeug:" << endl;
    cout << '\t' << "Hubraum: " << hubraum << "ccm" << endl;
    cout << '\t' << "Leistung: " << leistung << "kW" << endl;
    cout << '\t' << "Farbe: " << farbe << endl;
    cout << '\t' << "Räder: " << anzahl_raeder << endl;
    cout << '\t' << "Zustand: " << zustand << "%" << endl;
}

/**
 * Tunt das Fahrzeug. Dabei wird die Leistung erhöht und der Zustand des
 * Fahrzeugs verschlechtert.
 */
void Fahrzeug::tunen() {
    leistung *= 1.15;
    zustand -= 15;
    if (zustand <= 0) {
        cout << "Das Fahrzeug wurde kaputt getunt." << endl;
        zustand = 0;
    }
}

/**
 * Fährt das Fahrzeug wodurch dessen Zustand verschlechter wird.
 * strecke: zurückgelegte Strecke in km
 */
void Fahrzeug::fahren(long strecke) {
    zustand -= 0.00002 * strecke;
    if (zustand <= 0) {
        cout << "Das Fahrzeug wurde kaputt gefahren." << endl;
        zustand = 0;
    }
}
