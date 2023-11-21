#include <iostream>
#include "RushHour.h"
using namespace std;

int const N = 8;

//int main(){
//    string g[6];
//    bool isGameover = false;
//    cout << "Enter initial grid: ";
//    for (int i = 0; i < 6; i++)
//    {
//        cin >> g[i];
//    }
//    
//    RushHour rh(g);
//    while(!rh.isSolved()){
//        int car; int step;
//        rh.print();
//        cout << "Move a car: ";
//        cin >> car >> step;
//        
//        switch (rh.moveCar(car, step)){
//            case 0:
//                break;
//            case 1:
//                cout << "Invalid car or step! Try again. " << endl;
//                continue;
//            case 2:
//                cout << "Hit! Try again. " << endl;
//                continue;
//        }
//    }
//    rh.print();
//    cout << "Congrats! You finished in 17 steps. " << endl;
//	  return 0;
//}