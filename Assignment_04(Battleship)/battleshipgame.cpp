// Name:       Yu Ching Hei
// Student ID: 1155193237
// Email:      chyu@link.cuhk.edu.hk

#include <iostream>
#include "battleshipboard.h"
/* You may add extra standard library headers if you see fit */
//#include <ctype.h>

using namespace std;

int main() {
    // prompt user for seed, game mode, ships setup before gameplay
    unsigned int seed;
    bool gameMode = false;
    bool manualSetup = false;

    // TODO: Add your code
    
    cout << "Enter seed: ";
    cin >> seed;
    srand(seed);
    inputYesNo(gameMode, "Play in game mode (Y/N)? ");
    inputYesNo(manualSetup, "Manually set up ships (Y/N)? ");


    // initialize boards and fleets
    char myBoard[N][N] = { ' ' }, enBoard[N][N] = { ' ' };
    Fleet myFleet = { "Your", {5, 4, 3, 3, 2} };
    Fleet enFleet = { "Enemy", {5, 4, 3, 3, 2} };

    fill(myBoard[0] + 0, myBoard[N - 1] + N, BLANK);
    fill(enBoard[0] + 0, enBoard[N - 1] + N, BLANK);

    if (manualSetup) {
        printBoards(enBoard, myBoard, gameMode);
        manuallyPlaceShips(myBoard);
    }
    else {
        randomlyPlaceShips(myBoard);
    }
    randomlyPlaceShips(enBoard);

    bool gameOver = false;
    string winner = "";
    Fleet* attacker = &myFleet, * opponent = &enFleet, * tmp = NULL;

    // start the game loop
    for (int round = 1; !gameOver; round++) {
        cout << "Round " << round << ":" << endl;
        printBoards(enBoard, myBoard, gameMode);
        printStatus(enFleet, myFleet);

        // get shoot location
        int x, y;
        while (true) {
            bool ok;
            if (attacker == &myFleet) {
                ok = getHumanMove(y, x) && isValidShoot(enBoard, y, x);
                if (!ok)
                    cout << "Invalid shot location!" << endl;
            }
            else {
                ok = getComputerMove(myBoard, y, x) && isValidShoot(myBoard, y, x);
            }
            if (ok)
                break;
        }


        // carry out the shoot
        bool hit = shoot(attacker == &myFleet ? enBoard : myBoard, y, x, opponent);
        if (hit) {
            // check if all opponent ships have sunk
            // (if so, set winner and game over flag to leave the loop)
            // TODO: Add your code
            int sunkCount = 0;
            for (int i = 0; i < 5; i++){
                if (0 == opponent->alive[i]){
                    sunkCount++;
                }
            }
            gameOver = sunkCount == 5;
            winner = gameOver ? attacker->name : "";
        }

        // swap the player's turn
        tmp = attacker;
        attacker = opponent;
        opponent = tmp;
    }

    // print final gameboards, game over message and the winner
    // TODO: Add your code
    printBoards(enBoard, myBoard, false);
    printStatus(enFleet, myFleet);
    cout << "Game over! " << endl;
    cout << winner << " fleet wins! " << endl;
}
