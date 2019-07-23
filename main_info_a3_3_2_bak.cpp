#include <iostream>

using namespace std;

int main () {
    const unsigned int n = 4;
    unsigned int matrix[n][n];
    /* START */

    /* GOAL */
    // 1  2  3  4
    // 12 13 14  5
    // 11 16 15  6
    // 10  9  8  7

    fill_n(*matrix, n * n, 0); // initialised array to zero

    int dirs[4][2] = {{1 ,0}, {0, -1}, {-1, 0}, {0, 1}};
    unsigned int x = 0, y = 0; // current pos in array
    int dir = 0; // current direction
    unsigned int c = 1; // counter

    while(c <= n * n) { // do until middle of array is reached
        matrix[y][x] = c++; // write current counter value to array
        // <inside array bounds?> && !<cell was written before?>
        if (x + dirs[dir][0] < n && x + dirs[dir][0] > 0 && y + dirs[dir][1] < n && y + dirs[dir][1] > 0 &&
                !matrix[x + dirs[dir][0]][y + dirs[dir][1]]) {
            x += dirs[dir][0];
            y += dirs[dir][1];
        }
        else {
            // (1 ,0) -> (0, -1) -> (-1, 0) -> (0, 1)
            if (dir != 3) dir++;
            else dir = 0;
        }
    }

    /* END */
    for (unsigned int r = 0; r < n; ++r){
        for (unsigned int c = 0; c < n; ++c){
            if (matrix [r][c] < 10){
                cout << ' ';
            }
            cout << matrix[r][c] << ' ';
        }
        cout << endl;
    }

    return 0;
}