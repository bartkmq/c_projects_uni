#include <iostream>
#include <cstring>

using namespace std;

#define GRID_SIZE 11

void init_grid(char[]);
void print_grid(const char[]);
int map_1d(int, int, int = 0, int = 0);
void set_sign(char[], int, int, int);
int get_sign(const char[], int, int);
int check_winner(char[]);

void init_grid(char grid[]) {
    for (int x = 0; x < GRID_SIZE; x++) {
        for (int y = 0; y < GRID_SIZE; y++) {
            grid[map_1d(x, y)] = ((y + 1) % 4 && (x + 1) % 4) ? ' ' : '#';
        }
    }
}

void print_grid(const char grid[]) {
    for (int x = 0; x < GRID_SIZE; x++) {
        for (int y = 0; y < GRID_SIZE; y++) {
            cout << grid[map_1d(x, y)];
        }
        cout << endl;
    }
    cout << endl;
}

// calculate 1d array pos
// big: which sign; small: pos inside specific sign or global if big == 0
int map_1d(int x_small, int y_small, int x_big, int y_big) {
    // maps 0 -> 0; 1 -> 4; 2 -> 8
    // converts big grid coords to global small grid coords
    int x = (x_big == 0) ? 0 : x_big * 4;
    int y = (y_big == 0) ? 0 : y_big * 4;
    // standard 2d to 1d array mapping
    return (y + y_small) * GRID_SIZE + x + x_small;
}

void set_sign(char grid[], int x_big, int y_big, int player) {
    char pm1[3][3] = {{'X', ' ', 'X'},
                      {' ', 'X', ' '},
                      {'X', ' ', 'X'}};

    char p1[3][3] = {{' ', 'O', ' '},
                     {'O', 'O', 'O'},
                     {' ', 'O', ' '}};

    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            grid[map_1d(x, y, x_big, y_big)] = pm1[y][x];
        }
    }
}

// 0 -> none; -1 -> player0; 1 -> player1
// and 0 -> invalid coords
int get_sign(const char grid[], int x_big, int y_big) {
    int x = 0;
    // check of middle of big grid cell
    if (x_big >= 0 || x_big < 3 || y_big >= 0 || y_big < 3) {
        switch (grid[map_1d(1, 1, x_big, y_big)]) {
            case 'X': x = -1; break;
            case 'O': x = 1; break;
        }
    }
    return x;
}

int check_winner(char grid[]) {
    /*for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            if (get_sign(grid, x, y) != -1) {
                int ways[][2] = {{1, 0}, {1, 0}, {1, 1}, {1, 1}, };
            }
        }
    } */
    int start[8] = { 0, 3, 6, 0, 1, 2, 0, 2 };
    int incr[8] = { 1, 1, 1, 3, 3, 3, 4, 2 };
    for (int i = 0; i < 8; i++) {
        int sum = 0;
        for (int j = 0; j < 3; j++)
            sum += get_sign(grid, start[i], incr[j]);
        if (abs(sum) == 3)
            return (sum / 3);
    }
    return 0;
}


int main() {
    char grid[GRID_SIZE * GRID_SIZE];

    init_grid(grid);

    cout << "Bitte geben sie auf Anfrage x, y"
            " getrennt durch Leerzeichen ein." << endl;
    int moves = 0;
    char player = 'A';
    bool running = true;
    while (running) {
        cout << "Spieler " << player << " ist an der Reihe: ";
        int x_in, y_in;
        cin >> y_in >> x_in;
        set_sign(grid, x_in - 1, y_in - 1, (player == 'A') ? -1 : 1);
        moves++;
        print_grid(grid);
        switch(check_winner(grid)) {
            case -1: cout << "Spieler A hat gewonnen."; running = false; break;
            case 1: cout << "Spieler B hat gewonnen."; running = false; break;
            case 0: if (moves == 9) {
                    cout << "Unentschieden.";
                    running = false;
                }
        }
        player = (player == 'A') ? 'B' : 'A';
    }
}
