// Name:       Yu Ching Hei
// Student ID: 1155193237
// Email:      chyu@link.cuhk.edu.hk

#include <iostream>
#include <iomanip>
#include <cctype>
#include "battleshipboard.h"
/* You may add extra standard library headers if you see fit */

using namespace std;

// Return a 5-letter string showing which ships of the specified fleet have sunk
string fleetStatus(Fleet fleet) {
    int const DEAD[5] = {0, 0, 0, 0, 0};
    string output;
    for (int i = 0; i < 5; i++) {
        if (fleet.alive[i] > DEAD[i]) {
            output.append(SHIP_TYPE[i], 0, 1);
        }
        else {
            output.append(1,HIT);
        }
    }
    return output;
}

// Print the status string of each fleet
void printStatus(Fleet fleet1, Fleet fleet2) {
    cout << setw(N * 2 + 2) << left;
    cout << fleet1.name + " Fleet: " + fleetStatus(fleet1) << "  ";
    cout << setw(N * 2 + 2) << left;
    cout << fleet2.name + " Fleet: " + fleetStatus(fleet2) << endl;
}

// Print the user and computer game boards side by side
void printBoards(char board1[][N], char board2[][N], bool gameMode) {
    cout << setw(N * 2 + 2) << left << "Enemy Ocean" << "  "
        << setw(N * 2 + 2) << left << "Your Ocean" << endl << right;

    // print column headers for both game boards
    for (int i = 0; i < 2; i++) {
        cout << string(2 + i * 2, ' ');
        for (int j = 0; j < N; j++)
            cout << setw(2) << char('A' + j);
    }
    cout << endl;

    // print row indexes and board content for both game boards
    if (!gameMode){
        for(int y = 1; y <= N; y++) {
            //Enemy board
            cout << setw(2) << y << right;
            for (int x = 0; x < N; x++){
                cout << setw(2) << board1[y - 1][x] << right;
            }
            cout << "  ";
            //My board
            cout << setw(2) << y << right;
            for (int x = 0; x < N; x++){
                cout << setw(2) << board2[y - 1][x] << right;
            }
            cout << endl;
        }
    }
    else {
        for(int y = 1; y <= N; y++) {
            //enemy board, either HIT/MISS/BLANK
            cout << setw(2) << y << right;
            for (int x = 0; x < N; x++){
                cout << setw(2) << right;
                if (board1[y - 1][x] != HIT && board1[y - 1][x] != MISS) {
                    cout << BLANK;
                }
                else {
                    cout << board1[y - 1][x];
                }
            }
            cout << "  ";
            //My board, remain same
            cout << setw(2) << y << right;
            for (int x = 0; x < N; x++){
                cout << setw(2) << board2[y - 1][x] << right;
            }
            cout << endl;
        }
    }
}

// Check if the specified location (y, x) is within the board
bool isValidCell(int y, int x) {
    if (y < N && x < N)
        return true;
    else 
        return false;
    
}

// Check if a shoot location (y, x) is valid
bool isValidShoot(char board[][N], int y, int x) {
    // TODO: Add your code
    if (isValidCell(y, x) &&
        board[y][x] != HIT &&
        board[y][x] != MISS)
        {
            return true;
        }
    else {
        return false;
    }
}

// Convert ship letter to its index in the ship type array
int indexOf(char ship) {
    for (int i = 0; i < 5; i++) {
        if (ship == SHIP_TYPE[i][0])
            return i;
    }
    return -1;
}

// Carry out a shot on the specified board at location (y, x)
bool shoot(char board[][N], int y, int x, Fleet* fleet) {
    if (board[y][x] != BLANK)
    {
        int shipCat = indexOf(board[y][x]);
        fleet->alive[shipCat]--;
        if (fleet->alive[shipCat] == 0)
            cout << fleet->name << " " << SHIP_TYPE[shipCat] << " sank!" << endl;
        board[y][x] = HIT;
        return true;
    }
    board[y][x] = MISS;
    return false;
}

// Get location (y, x) from the user via console input
bool getCellFromConsole(int& y, int& x) {
    char col; int row;
    cin >> col >> row;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }

    col = tolower(col) - 'a';
    row -= 1;
    if(isValidCell(row,col)) {
        y = row;
        x = col;
        return true;
    }
    return false;
}

// Get a random location (y, x) within board size
void getRandomCell(int& y, int& x) {
    y = rand() % N;
    x = rand() % N;
}

// Prompt the user for shoot location (y, x)
bool getHumanMove(int& y, int& x) {
    cout << "Enter attack location: ";
    return getCellFromConsole(y, x);
}

// Get shoot location (y, x) by the computer player's strategy
bool getComputerMove(char board[][N], int& y, int& x) {
    // try to shoot neighborhood of an existing hit first
    const int TRIALS = 1000;
    int dy[] = { -1,  0,  1,  0 };  // deltas for getting the cell at 
    int dx[] = { 0,  1,  0, -1 };  // North, East, South, West around (y, x)
    for (int t = 0; t < TRIALS; t++) {
        int i, j;
        getRandomCell(i, j);
        if (board[i][j] == HIT) {
            int st = rand() % 4;
            for (int k = 0; k < 4; k++) {
                int r = (st + k) % 4;  // random start in dy, dx
                if (isValidCell(i + dy[r], j + dx[r]) &&
                    board[i + dy[r]][j + dx[r]] != HIT &&
                    board[i + dy[r]][j + dx[r]] != MISS) {
                    y = i + dy[r]; x = j + dx[r];
                    return true;
                }
            }
        }
    }

    // shoot at a random location
    getRandomCell(y, x);
    return true;
}

// Place ship on board in specified orientation (vertical or horizontal)
bool placeShip(char board[][N], int y, int x, char ship, bool vertical = false) {
    int shipLen = SHIP_SIZE[indexOf(ship)];
    if (!vertical) {
        for (int i = 0; i < shipLen; i++) {
            if (board[y][x + i] != BLANK || !isValidCell(y, x + i)){
                return false;
            }
        }
        for (int i = 0; i < shipLen; i++) {
            board[y][x + i] = ship;
        }
        return true;
    }
    else {
        for (int i = 0; i < shipLen; i++) {
            if (board[y + i][x] != BLANK || !isValidCell(y + i, x)){
                return false;
            }
        }
        for (int i = 0; i < shipLen; i++) {
            board[y + i][x] = ship;
        }
        return true;
    }
}

// Randomly place all ships on board
void randomlyPlaceShips(char board[][N]) {
    for (int k = 0; k < 5; k++) {
        char ship = SHIP_TYPE[k][0];
        while (true) {
            int y, x;
            bool vertical = bool(rand() % 2);
            getRandomCell(y, x);
            if (placeShip(board, y, x, ship, vertical))
                break;
        }
    }
}

// Manually place all ships on board
void manuallyPlaceShips(char board[][N]) {
    // TODO: Add your code
    for (int k = 0; k < 5; k++) {
        char ship = SHIP_TYPE[k][0];
        while (true) {
            char ori;
            int y, x;
            bool vertical;

            cout << "Enter h/v and location for " << SHIP_TYPE[k] << ": ";
            cin >> ori;
            if (!getCellFromConsole(y, x)) {
                cout << "Invalid ship location! " << endl;
                continue;
            }
            
            ori = toupper(ori);
            if ('V' == ori) {
                vertical = true;
            }
            else if ('H' == ori) {
                vertical = false;
            }
            else {
                cout << "Invalid ship location! " << endl;
                continue;
            }
            if (!placeShip(board, y, x, ship, vertical)) {
                cout << "Invalid ship location! " << endl;
                continue;
            }
            else
                break;
        }  
    }   
}

/*  prompt input of yes an no
    @param  &output: pass value to variable 
    @param  prompt: string output prompt */
void inputYesNo(bool& output, string prompt){
    char input;
    while(true) {
        cout << prompt; 
        cin >> input;
        input = toupper(input);
        if (input == 'Y') {
            output = true;
        }
        else {
            output = false;
        }
        break;
    }
}
