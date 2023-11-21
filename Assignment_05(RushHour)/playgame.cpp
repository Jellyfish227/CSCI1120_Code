#include <iostream>
#include "RushHour.h"
using namespace std;

int const N = 8;

int main(){
    string g[6];
    bool isGameover = false;
    cout << "Enter initial grid: ";
    for (int i = 0; i < 6; i++)
    {
        cin >> g[i];
    }
    
    RushHour rh(g);
    while(!isGameover){
        int car; int step;
        print();
        cout << "Enter car and steps: ";
        cin >> car >> step;
        switch (moveCar(car, step))
            case 0:
                break;
            case 1:
                cout << "Car not exist or step is zero." << endl;
                continue;
            case 2:
                cout << "Hit wall or hit car or exeed the moving boundary" << endl;
                continue;
    }
    
}