// Name:       Yu Ching Hei
// Student ID: 1155193237
// Email:      chyu@link.cuhk.edu.hk

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

int main() {
	string str = "Draw";
	stringstream ss(str);

	int num;
	ss >> num;
	if (!ss.fail())
	{
		cout << "isNum" << endl;
		cout << num << endl;
	}
	else
	{
		char d;
		ss.clear();
		ss << str;
		ss >> d;
		cout << d;
	}
	
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
