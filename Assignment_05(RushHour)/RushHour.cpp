//Student Name: Yu Ching Hei
//SID: 1155193237
//email: chyu@link.cuhk.edu.hk

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
			if (car == (grid[y][x] - '0')) {
				tempy = y;
				tempx = x;
				if (grid[y + 1][x] == grid[tempy][tempx] 
					|| grid[y][x + 1] == grid[tempy][tempx]) {
					row = tempy;
					col = tempx;
					return true;
				}
			}
		}	
	}
	return false;
}

int RushHour::moveCar(int car, int step) { //positive = down or right; negative = up or left;
	const int INIT = -255;
	static int total = INIT;
	if (INIT == total) //ifndef temp //recursion guard
		total = step; //define temp = step

	int row = 0; int col = 0;

	if (0 == total || !locateCar(car, row, col)) {
		total = INIT;
		return 1;
	}
	else {
		//check orientation
		static bool isHorizontal = false;
		if (grid[row][col] == grid[row][col + 1]) {
			isHorizontal = true;
		}
		else if (grid[row][col] == grid[row + 1][col]) {
			isHorizontal = false;
		}

		//check direction
		int direction = 0;
		if (total != INIT) {
			if (total < 0)
				direction = -1;
			else
				direction = 1;
		}

		//check length
		static int len = INIT;
		if (INIT == len) {
			len = 1;
			int temp;
			if (isHorizontal) {
				temp = col;
				while (grid[row][temp + 1] == grid[row][temp]) {
					len++;
					temp++;
				}
			}
			else {
				temp = row;
				while (grid[temp + 1][col] == grid[temp][col]) {
					len++;
					temp++;
				}
			}
		}

		//check hit
		static bool isHit = false;
		if (!isHit)
		{
			int offset = 0;
			for (int i = 1; i <= abs(total); i++){
				if (1 == direction)
					offset = len - 1 + i;
				else
					offset = direction * i;

				if (isHorizontal)
				{
					if (!(grid[row][col + offset] == '.'
						|| grid[row][col + offset] == car + '0')) {
						isHit = true;
						break;
					}
				}
				else {
					if (!(grid[row + offset][col] == '.'
						|| grid[row + offset][col] == car + '0')) {
						isHit = true;
						break;
					}
				}
			}
		}

		//move and recursion
		static int move = 0;
		if (abs(step) > 0) {
			return moveCar(car, abs(step) - 1);
		}
		else if (0 == step && !isHit) {
			if (isHorizontal) {
				if (direction == 1) {
					for (int i = 0; i < len; i++) {
						grid[row][col + i] = '.';
					}
					for (int i = 0; i < len; i++) {
						grid[row][col + total + i] = car + '0';
					}
				}
				else {
					for (int i = 0; i < len; i++) {
						grid[row][col + len - 1 - i] = '.';
					}
					for (int i = 0; i < len; i++) {
						grid[row][col - abs(total) + i] = car + '0';
					}
				}
			}
			else {
				if (direction == 1) {
					for (int i = 0; i < len; i++) {
						grid[row + i][col] = '.';
					}
					for (int i = 0; i < len; i++) {
						grid[row + total + i][col] = car + '0';
					}
				}
				else {
					for (int i = 0; i < len; i++) {
						grid[row + len - 1 - i][col] = '.';
					}
					for (int i = 0; i < len; i++) {
						grid[row - abs(total) + i][col] = car + '0';
					}
				}
				
			}
			totalSteps += abs(total);
			move = total = len = INIT;
			isHit = false;
			return 0;
		}
		else {
			move = total = len = INIT;
			isHit = false;
			return 2;
		}
	}
}

bool RushHour::isSolved() const {
	if (0 + '0' == grid[3][6] && 0 + '0' == grid[3][7]) {
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