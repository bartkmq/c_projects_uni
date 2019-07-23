#include <iostream>

using namespace std;

/*
   1 2 3

   4 5 6

   7 8 9

     0
 */

// check if (x, y) is valid pos in above grid, (0, 0) -> upper left corner
bool valid_pos(int x, int y) {
    return (x >= 0 && x < 3 && y >= 0 && y < 3) || (x == 1 && y == 3);
}

// recursive fun., starting at (x, y) will find out all possibilities from there
void possibilities(int x, int  y, int n, int &total) {
    if (n == 7) {
        total++;
        return;
    }

    const char jumps[8][2] = {{1, -2}, {2, -1}, {2, 1}, {1, 2},
                        {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}};
    int sum = 0;
    for (int i = 0; i < 8; i++) {
        int nx = x + jumps[i][0];
        int ny = y + jumps[i][1];
        if (valid_pos(nx, ny)) {
            possibilities(nx, ny, n + 1, total);
        }
    }
}

int main() {
    // call rec. fun. on every key
    int sum = 0;
    int keys[62] = {};
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (!valid_pos(i, j)) continue;
            int total = 0;
            possibilities(i, j, 1, total);
            keys[i * 3 + j] = total;
            sum += total;
        }
    }
    // print out possibilities per key
    int x = 0;
    possibilities(1, 3, 1, x);
    cout << keys[0] << "\t" << keys[1] << "\t" << keys[2] << endl;
    cout << keys[3] << "\t" << " " << keys[4] << "\t" << keys[5] << endl;
    cout << keys[6] << "\t" << keys[7] << "\t" << keys[8] << endl;
    cout << "\t" << x << endl;

    cout << "Insgesamt: " << sum << endl;
    return 0;
}