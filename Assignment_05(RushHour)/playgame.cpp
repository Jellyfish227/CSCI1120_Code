//Student Name: Yu Ching Hei
//SID: 1155193237
//email: chyu@link.cuhk.edu.hk

#include <iostream>
#include "RushHour.h"
using namespace std;

int main() {
    string g[6];

    cout << "Enter initial grid: ";
    for (int i = 0; i < 6; i++){
        cin >> g[i];
    }

    RushHour rh(g);
    int gameEnd = -1;
    rh.print();
    
    while (gameEnd == -1) {
        int car; int step;
        cout << "Move a car: ";
        cin >> car >> step;

        switch (rh.moveCar(car, step)) {
        case 0:
            break;
        case 1:
            cout << "Invalid car or step! Try again. " << endl;
            continue;
        case 2:
            cout << "Hit! Try again. " << endl;
            continue;
        }

        rh.print();

        if (!rh.isSolved() && rh.getTotalSteps() > 100) {
            gameEnd = 1;
        }
        else if (rh.isSolved()){
            gameEnd = 0;
        }
    }
    if (gameEnd == 1) 
        cout << "Oops! You could not solve in 100 steps. " << endl;
    else if (gameEnd == 0)
        cout << "Congrats! You finished in " << rh.getTotalSteps() << " steps. " << endl;
    return 0;
}
