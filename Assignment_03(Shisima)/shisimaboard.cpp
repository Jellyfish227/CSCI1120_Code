// Name:       Yu Ching Hei
// Student ID: 1155193237
// Email:      chyu@link.cuhk.edu.hk

#include "shisimaboard.h"
#include <iostream>
using namespace std;

/* Returns the state of position pos of the game board. */
int boardState(int board, int pos) {
    int den = 1;
    for (int i = 8 - (pos - 1); i > 0; i--) {
		den *= 10;
	}

    return (board / den) % 10;
}

// /* Prints the board to the screen. DO NOT MODIFY! */
// void printBoard(int board) {
//     cout << "  " << boardState(board, 1) << "-" << boardState(board, 2) << "-" << boardState(board, 3) << endl;
//     cout << " / \\|/ \\" << endl;
//     cout << boardState(board, 4) << "---" << boardState(board, 5) << "---" << boardState(board, 6) << endl;
//     cout << " \\ /|\\ /" << endl;
//     cout << "  " << boardState(board, 7) << "-" << boardState(board, 8) << "-" << boardState(board, 9) << endl;
// }

// /* Performs the task of player p moving a piece from position pos1 to position
//    pos2 of board. */
// bool movePiece(int& board, int pos1, int pos2, int p) {
//     // TODO: Add a return statement in order to compile
//     return false;

// }

// /* Checks if any player has formed a line of three pieces crossing the middle
//    of the board. */
// int formLine(int board) {
//     // TODO: Add a return statement in order to compile

//     return 0;
// }

// /* You may write a main() in this file for debugging purpose, but it must be
//    removed or commented in your submitted version. */