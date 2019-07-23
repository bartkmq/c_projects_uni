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

    #define dir_x dirs[dir][0]
    #define dir_y dirs[dir][1]

    fill_n(*matrix, n * n, 0); // initialise array to zero

    int dirs[4][2] = {{1 ,0}, {0, -1}, {-1, 0}, {0, 1}}; // right, down, left, up
    unsigned int dir = 0;
    unsigned int x = 0, y = 0; // current pos in array
    unsigned int c = 1; // counter

    while(c <= n * n) { // do until middle of array is reached
        matrix[y][x] = c++; // write current counter value to array
        // <inside array bounds?> && !<cell was written before?>
        if (x + dir_x < n && x + dir_x > 0 && y + dir_y < n && y + dir_y > 0 &&
                !matrix[x + dir_x][y + dir_y]) {
            x += dir_x;
            y += dir_y;
        }
        else // right:(1, 0) -> down:(0, -1) -> left:(-1, 0) -> up(0, 1) -> [right]
            dir = (dir != 3) ? dir + 1 : 0;
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