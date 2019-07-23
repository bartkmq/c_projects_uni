#include <stdio.h>
#include <iostream>

int main() {
    int n[3];

    cout << "Bitte 3 Integers eingeben!"
    for (int i = 0; i < 3; i++)
        cin >> n[i];

    int swapped = 0;
    while (1) {
        swapped = 0;
        for (int i = 0; i < 2; i++) {
            if (n[i] < n[i + 1]) {
                int t = n[i];
                n[i] = n[i + 1];
                n[i + 1] = t;
                swapped = 1;
                continue;
            }
        }
        if (swapped == 0)
            break;
    }
}
