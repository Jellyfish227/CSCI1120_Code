#include <iostream>
#include <math.h>
#include "RushHour.h"
using namespace std;

RushHour::RushHour(std::string g[]) : totalSteps(0) {
	grid[0].assign(8, '#');
	grid[7].assign(8, '#');
	for (int i = 0; i < 6; i++) {
		grid[i+1] = g[i];
	}
}

bool RushHour::locateCar(int car, int& row, int& col) const {
	int tempx = 0; int tempy = 0;
	bool isSpotted = false;

	for (int y = 1; y <= 6; y++) {
		for (int x = 1; x <= 6; x++) {
			if (isSpotted &&
				grid[y][x] == grid[y][tempx] && //Horizontal case
				grid[y][x] == grid[tempy][x]) { //Vertical case
				row = tempy;
				col = tempx;
				return true;
			}
			if (car == grid[y][x]) {
				tempy = y;
				tempx = x;
				isSpotted = true;
				continue;
			}
		}	
	}
	return false;
}

int RushHour::moveCar(int car, int step) { //positive = down or right; negative = up or left;
	//steps validation 
	//1. car exist in the grid by locateCar(), determin move left/right/up/down
	//2. Steps != 0
	//3. Enough space to move by step tiles without hitting, check valid or not each case
	/* return 0 = valid
		return 1 = car not exist or step is zero
		return 2 = hit other cars or border or go beyond the exit zone */
	static int temp = -9;
	if (-9 == temp) //ifndef temp //recursion guard
		temp = step; //define temp = step
	int row = 0; int col = 0;
	
	//moveCar() return value
	if (0 == temp || !locateCar(car, row, col)){
		return 1;
	} else {
		//check orientation
		static bool isHorizontal = false;
		if (grid[row][col] == grid[row][col + 1]) {
			isHorizontal = true;
		} else if (grid[row][col] == grid[row + 1][col]) {
			isHorizontal = false;
		}

		if (isHorizontal) {
			if (temp > 0) {
				while (grid[row][col + 1] == grid[row][col]){
					col++; //trasverse to the last cell
				}
				if (grid[row][col + step] == '.')
				{
					if (step > 0)
					{
						return moveCar(car, step - 1);
					}
					else
						totalSteps += temp;
					temp = -9;
					return 0;
				}
				else
				{
					temp = -9;
					return 2;
				}
			} else {
				if (grid[row][col + step] == '.')
				{
					if (step < 0)
					{
						return moveCar(car, step + 1);
					}
					else
						totalSteps += abs(temp);
					temp = -9;
					return 0;
				}
				else
				{
					temp = -9;
					return 2;
				}
			}
		} else {
			if (temp > 0)
			{
				while (grid[row + 1][col] == grid[row][col])
				{
					row++; // trasverse to the last cell
				}
				if (grid[row + step][col] == '.')
				{
					if (step > 0)
					{
						return moveCar(car, step - 1);
					}
					else
						totalSteps += temp;
					temp = -9;
					return 0;
				}
				else
				{
					temp = -9;
					return 2;
				}
			}
			else
			{
				if (grid[row + step][col] == '.')
				{
					if (step < 0)
					{
						return moveCar(car, step + 1);
					}
					else
						totalSteps += abs(temp);
					temp = -9;
					return 0;
				}
				else
				{
					temp = -9;
					return 2;
				}
			}
		}
	}
}

bool RushHour::isSolved() const {
	if (0 == grid[3][7]) {
		return true;
	}
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

//test main
//TODO: Remove upon finish
int main() {
	string g[6];
	for (int i = 0; i < 6; i++) {
		cin >> g[i];
	}
	RushHour rushHour(g);
	rushHour.print();
	return 0;
}