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

int main()
{
	int n = 4;

	int hi = 0, hj = 0;
	int ci = n-1, cj = 0;

	printboard(hi, hj, ci, cj, n);

	int move = 5;
	if (hj + move > n - 1) {
		hi += (hj + move) % (n - 1);
		hj += (n - 1) - (hj + move) % (n - 1);
	}
	cout << endl;

	printboard(hi, hj, ci, cj, n);

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
