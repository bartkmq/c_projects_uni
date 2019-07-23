#include <iostream>
/**
 * Beschreibung der Aufgabenlösung:
 * Es wird eine rekursive Funktion recv_jmp definiert die als Parameter die
 * Starttaste key und die Länge der aktuellen Mitgliedsnummer n entgegennimmt.
 * Beim ersten Aufruf liegt key im Intervall [1;9] (da 0 keine valide
 * Starttaste ist) und n bei der gewünschten Länge der Mitgliedsnummern(7).
 * In der Rekursionsvorschrift ruft die Funktion sich mehrmals selber auf mit
 * den möglichen Landepunkten/Tasten die von der aktuellen Taste key
 * durch einen Sprung erreicht werden können mit n = n - 1.
 * Da die Rekursionsverankerung angibt dass die Funktion
 * bei erreichen von n = 1 zurückkehrt (n = 1 entspricht dabei der
 * letzten Ziffer der Mitgliedsnummer), reduziert die Rekursionsvorschrift so
 * dass Problem, eine Mitgliedsnummer zu finden, um eine Ziffer dieser Nummer.
 * Die Funktion liefert dann als Rückgabewert die Anzahl der
 * möglichen Mitgliedsnummern, die von ihren Funktionsaufrufen gefunden
 * wurden.
 *
 * Die main Funktion wendet dann die Funktion recv_jmp auf jede Taste != 0 an
 * und summiert die zurückgelieferten Werte auf.
 * Der entstehende Wert entspricht der Anzahl der insgesamt möglichen, validen
 * Mitgliedsnummern.
 */

/**
 * Adjazenzlisten:
 * jump_targets[key][i] entspricht dem i-ten Landepunkt ausgehend von der
 * Taste key. Ein Knoten/Taste hat zwischen 0 und 3 Verbindungen.
 * Ein Landepunkt von -1 heißt dass dieser Landepunkt nicht existiert.
 */
int jump_targets[10][3] = {{4, 6, -1}, // Landepunkte von Taste 0 aus usw.
                           {6, 8, -1}, {7, 9, -1}, {4, 8, -1},  // 1, 2, 3
                           {0, 3, 9}, {-1, -1, -1}, {0, 1, 7},  // 4, 5, 6
                           {2, 6, -1}, {1, 3, -1}, {2, 4, -1}}; // 7, 8, 9

/**
 * Gibt die Anzahl der Mitgliedsnummern anfangend mit einer
 * bestimmten Taste zurück.
 * key: Starttaste
 * n: gewünschte Anzahl der Ziffern der Mitgliedsnummern
 */
int recv_jmp(int key, int n = 7) {
    /**
     * Rekursionsverankerung:
     * Abbruch wenn die letzte (7.) Stelle der Mitgliedsnummer erreicht wurde.
     * Dann zurückliefern dass eine Möglichkeit gefunden wurde.
     */
    if (n == 1) {
        return 1;
    }

    /**
     * Rekursionsvorschrift:
     * Die Funktion rekursiv auf alle existierenden Landemöglichkeiten der
     * aktuellen Taste key aufrufen und die
     * zurückgelieferte Anzahl der Möglichkeiten aufsummieren.
     */
    int sum = 0;
    for (int n_target = 0; n_target < 3; n_target++) {
        int target_key = jump_targets[key][n_target];
        if (target_key != -1) {
            sum += recv_jmp(target_key, n - 1); // als Parameter n - 1 benutzen
        }
    }
    /**
     * Die aufsummieren Möglichkeiten der unterliegenden Kombinationen
     * zurückgeben.
     */
    return sum;
}

int main() {
    /**
     * Die Anzahl an möglichen Mitgliedsnummern die mit einer bestimmten Taste
     * beginnen für alle Tasten != 0 aufsummieren.
     */
    int sum = 0;
    for (int key = 1; key < 10; key++) {
        sum += recv_jmp(key);
    }
    // Die Anzahl der validen Mitgliedsnummern ausgeben
    std::cout << "Möglichkeiten: " << sum << std::endl;
    return 0;
}