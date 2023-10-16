// TempCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void printboard(int hi, int hj, int ci,int cj, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (hi == i && hj == j) {
				cout << 'H';
			}
			else if (ci == i && cj == j) {
				cout << 'C';
			}
			else if (0 == i || n - 1 == i) {
				cout << '*';
			}
			else if (0 == j || n - 1 == j) {
				cout << '*';
			}
			else if (i == j || i == n - 1 - j) {
				cout << '*';
			}
			else {
				cout << ' ';
			}
		}
		cout << endl;
	}
}

int power(int base, int power) {
	for (int i = power; i > 0; i--) {
		base *= base;
	}

	return base;
}

int abs(int value) {
	value = power(power(value, 2), 0.5);

	return value;
}

bool isAdj(int pos1, int pos2) {
	/*Split position value into respective i and j*/
	
	/*Determine if Adj*/
	return true;
}

int main()
{
	int board = 102102102;

	int boardState(int board, int pos){
		int power = 8 - (pos - 1);
		int den = 1;
		const int BASE = 10;

		for (int i = 0; i < power; i++)
		{
			den *= BASE;
		}
		
		return (board / den) % 10;
	}

	cout << boardState(board, 1) << endl;

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
