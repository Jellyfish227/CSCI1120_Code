// Name:       Yu Ching Hei
// Student ID: 1155193237
// Email:      chyu@link.cuhk.edu.hk

#ifndef BATTLESHIPBOARD_H
#define BATTLESHIPBOARD_H
#include <string>

using std::string;

// Global constants
const int N = 8;             // board size
const char HIT = 'X';        // hit
const char MISS = 'O';       // miss
const char BLANK = '.';      // empty cell
const string SHIP_TYPE[5] = { "Carrier", "Battleship", "Destroyer", "Submarine", "Patrol Boat" };
const int SHIP_SIZE[5] = { 5, 4, 3, 3, 2 };  // initial health point of each ship

// Structures
struct Fleet {
    string name;   // a name denoting the player
    int alive[5];  // current health points of the player's ships
};

// Function prototypes
void printStatus(Fleet fleet1, Fleet fleet2);
void printBoards(char board1[][N], char board2[][N], bool gameMode);
bool isValidShoot(char board[][N], int y, int x);
bool shoot(char board[][N], int y, int x, Fleet* fleet);
bool getHumanMove(int& y, int& x);
bool getComputerMove(char board[][N], int& y, int& x);
void randomlyPlaceShips(char board[][N]);
void manuallyPlaceShips(char board[][N]);

/* You may put in extra function prototypes here if you have written extra
   functions in battleshipboard.cpp. */
void inputYesNo(bool& output, string prompt);

#endif // BATTLESHIPBOARD_H