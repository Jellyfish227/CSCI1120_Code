// TempCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int foo(int step){
	static int temp = -1;
	if (-1 == temp)	 // ifndef temp //recursion guard
		temp = step; // define temp = step
	
	cout << temp << " : " << step << endl;
	if (step > 0) {
		foo(step - 1);
	} else
		return 0;
}

int main(){
	foo(4);
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
