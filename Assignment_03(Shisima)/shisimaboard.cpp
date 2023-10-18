// Name:       Yu Ching Hei
// Student ID: 1155193237
// Email:      chyu@link.cuhk.edu.hk

#include "shisimaboard.h"
#include <iostream>
using namespace std;

/* Check adjacency
   @param pos,pos2 Coordinates */
bool isAdj(int pos1, int pos2) {
    int x1, y1;
    int x2, y2;

    int coo1 = Coo(pos1);
    int coo2 = Coo(pos2);

    x1 = (coo1 / 10) % 10;
    y1 = coo1 % 10;
    x2 = (coo2 / 10) % 10;
    y2 = coo2 % 10;

    int sumSqDis = power(x2 - x1, 2) + power(y2 - y1, 2);

    if (pos1 == 5 || pos2 == 5) {
        return true;
    }
    else if (sumSqDis <= 1) {
        return true;
    }
    else {
        return false;
    }
}

/* Mimic the pow function but only function in positive and integer indexes */
int power(int base, int index) {
    int output = 1;
    for (int i = 0; i < index; i++) {
        output *= base;
    }
    return output;
}

/* Returns the state of position pos of the game board. */
int boardState(int board, int pos) {
    int den = 1;
    for (int i = 8 - (pos - 1); i > 0; i--) {
		den *= 10;
	}

    return (board / den) % 10;
}

/* Prints the board to the screen. DO NOT MODIFY! */
void printBoard(int board) {
    cout << "  " << boardState(board, 1) << "-" << boardState(board, 2) << "-" << boardState(board, 3) << endl;
    cout << " / \\|/ \\" << endl;
    cout << boardState(board, 4) << "---" << boardState(board, 5) << "---" << boardState(board, 6) << endl;
    cout << " \\ /|\\ /" << endl;
    cout << "  " << boardState(board, 7) << "-" << boardState(board, 8) << "-" << boardState(board, 9) << endl;
}

/* Performs the task of player p moving a piece from position pos1 to position
   pos2 of board. */
bool movePiece(int& board, int pos1, int pos2, int p) {
    //input check
    if (pos1 >= 1 && pos1 <= 9 && pos2 >= 1 && pos2 <= 9 && 
        boardState(board, pos1) == p && 
        boardState(board, pos2) == 0 &&
        isAdj(pos1, pos2)) {
        board = board - p * (power(10, 9 - pos1)) + p * (power(10, 9 - pos2));
        return true;
    }
    else {
        return false;
    }
}

/* Checks if any player has formed a line of three pieces crossing the middle
   of the board. */
int formLine(int board) {
    if (boardState(board,5) != 0){
        int pos123 = 0;
        int index = 0;
        for (int i = 0; i < 9; i++) {
            if (boardState(board,i + 1) == boardState(board,5)) {
                pos123 += (i + 1) * power(10, index);
                index++;
            }
        }
        
        int p1 = (pos123 / 100) % 10;
        int p2 = (pos123 / 10) % 10;
        int p3 = pos123 % 10;

        if ((p2 - p1) == (p3 - p2)) {
            return boardState(board, 5);
        }
        else {
            return 0;
        }
    }
    else
        return 0;
    
}

/* Split position into coordinates, output 2 digit int representing (xy)
   @param board   Board
   @param p1,p2   Positions to Compare */
int Coo(int pos){
    int coordinates = 0;
    pos--;
    coordinates += 10 * (pos / 3);
    coordinates += (pos % 3);
    return coordinates;
}

 /* You may write a main() in this file for debugging purpose, but it must be
    removed or commented in your submitted version. */
//
//int main() {
//    int board = 102102102;
//    printBoard(board);
//    int p = 1;
//    int pos1, pos2;
//
//    while (p != 0) {
//        cin >> p;
//        cin >> pos1 >> pos2;
//        cout << boolalpha;
//        cout << "Coo of Pos1: " << Coo(pos1) << endl;
//        cout << "Coo of Pos2: " << Coo(pos2) << endl;
//        cout << "Board State p1 = p: " << (boardState(board, pos1) == p) << endl;
//        cout << "Board State p2 = 0: " << (boardState(board, pos2) == 0) << endl;
//        cout << "isAdj: " << isAdj(pos1, pos2) << endl;
//        cout << "condition: " << (pos1 >= 1 && pos1 <= 9 && pos2 >= 1 && pos2 <= 9) << endl;
//        cout << (boardState(board, pos1) == p) << endl;
//        cout << (boardState(board, pos2) == 0) << endl;
//
//        cout << movePiece(board, pos1, pos2, p) << endl;
//
//    }
//    
//    return 0;
//}