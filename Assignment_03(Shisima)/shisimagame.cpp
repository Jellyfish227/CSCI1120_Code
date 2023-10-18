// Name:       Yu Ching Hei
// Student ID: 1155193237
// Email:      chyu@link.cuhk.edu.hk

#include "shisimaboard.h"
#include <iostream>
using namespace std;

int main() {
	int board = 102102102;
	int pos1, pos2;
	int p;
	bool isGameOver = false;
	bool isPlayer1 = false; //initialize as imaginary player 0

	while (!isGameOver) { //game start

		isPlayer1 = !isPlayer1; //change player each round, changing to player 1 in first round
		p = isPlayer1 ? 1 : 2;
		
		printBoard(board); 
		
		bool isMoveValid = true;
		do{
			cout << "Player " << p << " (from to): ";
			cin >> pos1 >> pos2;
			isMoveValid = movePiece(board, pos1, pos2, p);
			if (!isMoveValid) {
				cout << "Invalid. Try again!" << endl;
			}
		} while (!isMoveValid);
		
		if (formLine(board) != 0){
			isGameOver = true;
			printBoard(board);
			cout << "Player " << formLine(board) << " wins!" << endl;
		}
		else
			continue;
	}
	return 0;
}
