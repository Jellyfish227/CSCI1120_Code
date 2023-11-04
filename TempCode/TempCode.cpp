// TempCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
using namespace std;

// void printboard(int hi, int hj, int ci,int cj, int n) {
// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < n; j++) {
// 			if (hi == i && hj == j) {
// 				cout << 'H';
// 			}
// 			else if (ci == i && cj == j) {
// 				cout << 'C';
// 			}
// 			else if (0 == i || n - 1 == i) {
// 				cout << '*';
// 			}
// 			else if (0 == j || n - 1 == j) {
// 				cout << '*';
// 			}
// 			else if (i == j || i == n - 1 - j) {
// 				cout << '*';
// 			}
// 			else {
// 				cout << ' ';
// 			}
// 		}
// 		cout << endl;
// 	}
// }

// int power(int base, int power) {
// 	for (int i = power; i > 0; i--) {
// 		base *= base;
// 	}

// 	return base;
// }

// int abs(int value) {
// 	value = power(power(value, 2), 0.5);

// 	return value;
// }

// bool isAdj(int pos1, int pos2) {
// 	/*Split position value into respective i and j*/
	
// 	/*Determine if Adj*/
// } 


// int boardState(int board, int pos) {
//     // TODO: Add a return statement in order to compile
//     int den = 1;

//     for (int i = 8 - (pos - 1); i > 0; i--) {
// 		den *= 10;
// 	}

//     return (board / den) % 10;
// }

int const N = 15;
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
    // TODO: Add your code
    if (gameMode){
        for(int i = 1; i < N; i++) {
            cout << setw(2) << i << right;
            for (int j = 0; j < N; j++){
                cout << setw(2) << board1[i - 1][j] << right;
            }
            cout << "  ";
            cout << setw(2) << i << right;
            for (int j = 0; j < N; j++){
                cout << setw(2) << board2[i - 1][j] << right;
            }
            cout << endl;
        }
    }
    else {
        for (int i = 1; i <= N; i++){
            for (int j = 0; j < 2; j++)
            {
                cout << setw(3) << i << right;
                cout << setw(2 * N) << BLANK << right;
            }
            
        }
        
    }
}

int main()
{
	char myBoard[N][N] = { ' ' }, enBoard[N][N] = { ' ' };
	

	fill(myBoard[0] + 0, myBoard[N - 1] + N, BLANK);
    fill(enBoard[0] + 0, enBoard[N - 1] + N, BLANK);

	printBoards(enBoard, myBoard, true);
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
