#include <iostream>

using namespace std;

int main () {
    const unsigned int n = 6;
    unsigned int matrix[n][n];
    /* START */

    /* GOAL */
    // 1  2  3  4
    // 12 13 14  5
    // 11 16 15  6
    // 10  9  8  7

    fill_n(*matrix, n * n, 0); // initialised array to zero

    enum Dir { right, down, left, up};
    unsigned int state = right;

    unsigned int x = 0, y = 0; // current pos in array
    unsigned int c = 1; // counter

    while(c <= n * n) { // do until middle of array is reached
        matrix[y][x] = c++; // write current counter value to array
        switch(state) {
            case right:
                if(x != (n - 1) && !matrix[x + 1][y]) // <right end not reached?> && !<next element written before?>
                    x++; // go to the right
                else {
                    state++; // now go down and
                    y++;     // move one down
                }
                break;
            case down:
                if (y != (n - 1) && !matrix[x][y + 1])
                    y++;
                else {
                    state++; // left
                    x--;
                }
                break;
            case left:
                if (x != 0 && !matrix[y][x - 1])
                    x--;
                else {
                    state++; // up
                    y--;
                }
                break;
            case up:
                if (y != 0 && !(matrix[y-1][x]))
                    y--;
                else {
                    state = right;
                    x++;
                }
                break;
            default: cout << "ERROR" << endl; // should not happen
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