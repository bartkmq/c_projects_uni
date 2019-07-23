#include <iostream>

using namespace std;

/**
 * Telephone keypad layout:
 * 1 2 3
 * 4 5 6
 * 7 8 9
 *   0
 */

bool valid_pos(int x, int y) { // valid if in 3x3 || 0
    return (x >= 0 && x < 3 && y >= 0 && y < 3) || (x == 1 && y == 3);
}

// pos/x, pos/y, number of total possibilities for a key, length of member nr
void recv_jmp(int x, int y, int &possibilities, int n = 7) {
    if (n == 7 && x == 1 && y == 3) { // first number can't be key 0
        return;
    }

    if (n == 1) { // reached last nr for this key
        possibilities++;
        return;
    }

    int jumps[8][2] = {{1, -2}, {2, -1}, {2, 1}, {1, 2},
                       {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}};
    for (int i = 0; i < 8; i++) {
        int nx = x + jumps[i][0];
        int ny = y + jumps[i][1];
        if (valid_pos(nx, ny)) {
            recv_jmp(nx, ny, possibilities, n - 1);
        }
    }
}

int main() {
    int sum = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (valid_pos(j, i)) {
                int total = 0;
                recv_jmp(j, i, total);
                sum += total;
            }
        }
    }
    cout << "Möglichkeiten insgesamt: " << sum << endl;
    return 0;
}