#include <iostream>
#include "RushHour.h"
using namespace std;

RushHour::RushHour(std::string g[]) : totalSteps(0) {
	grid[0].assign(8, '#');
	grid[7].assign(8, '#');
	for (int i = 0; i < 8; i++) {
		grid[i+1] = g[i];
	}
}

bool RushHour::locateCar(int car, int& row, int& col) const {
	return false;
}

int RushHour::moveCar(int car, int step) {
	return 0;
}

bool RushHour::isSolved() const {
	return false;
}

int RushHour::getTotalSteps() const {
	return totalSteps;
}

void RushHour::print() const {
	for (string row : grid) {
		cout << row << endl;
	}
	cout << "Steps: " << getTotalSteps() << endl;
}

int main() {
	string g[6];

	for (int i = 0; i < 6; i++) {
		char temp[9];
		cin >> temp;
		g[i] = (string)temp;
	}

	RushHour rushHour(g);
	rushHour.print();
	return 0;
}