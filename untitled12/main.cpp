#include <stdio.h>
#include <iostream>

using namespace std;

#define len 5

int main() {
    int n[len];

    cout << "Bitte " << len << " Zahlen eingeben!" << endl;
    for (int i = 0; i < len; i++)
        cin >> n[i];

    bool swapped = true;
    while (swapped) {
        swapped = false;
        for (int i = 0; i < len - 1; i++) {
            if (n[i] > n[i + 1]) {
                int t = n[i];
                n[i] = n[i+1];
                n[i+1] = t;
                swapped = true;
                continue;
            }
        }
    }

    cout << "Die Zahlen sortiert.\n";
    for (int i = 0; i < len; i++)
        cout << n[i] << endl;

}
