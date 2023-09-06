// Lec_01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    cout << "Hello World!\n";

    int a = 10;
    double b = 10.0;    //the .0 is discarded
    
    int oct = 017;    //The 0 in the front indicates an octal number, thus output 15(in decimal)
    int hex = 0xf;  //The 0x in the front indicates a hexadecimal number, thus output 15

    
    cout << oct << endl << hex << endl;
    
    return 0;
}

