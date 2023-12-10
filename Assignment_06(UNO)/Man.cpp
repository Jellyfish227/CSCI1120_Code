// Name:       Yu Ching Hei
// Student ID: 1155193237
// Email:      chyu@link.cuhk.edu.hk

#include <iostream>
#include <iomanip>
// You may add additional headers if needed
#include <sstream>

#include "Man.h"

using namespace std;

Man::Man() : Player() {
    setName(getName() + " (Man)");
}

int Man::pickCard(GameState& uno) {
    bool haveMatch = false;
    int counter = 0;
    vector<bool> matchArr(handSize(), false);
    for (int i = 0; i < handSize(); i++)
    {
        //print selectable index
        string sel = "";
        sel += "[";
        if (hand.at(i)->match(uno.discardPile->top()))
        {
            sel += to_string(i);
            haveMatch = true;
            matchArr.at(i) = true;
        }
        else
            sel += "x";
        sel += "]";
        cout << setw(4) << right << sel;

        cout << hand.at(i)->toString() << " ";

        //counter for 10 card/line
        counter++;
        if (counter == 10 || (uno.drawPile->size() == 0 && hand.at(i) == hand.back()))
        {
            cout << endl;
            counter = 0;
        }
        // Show the [D]raw option if draw pile still has cards.
        if (uno.drawPile->size() != 0 && hand.at(i) == hand.back())
        {
            cout << " [D]raw" << endl;
        }
    }

    if (!haveMatch && uno.drawPile->size() == 0) 
        return PASSED;
    
    while (true)
    {
        string s;
        cout << "Enter option: ";
        cin >> s;
        stringstream ss(s);
        
        char inC = '\0';
        int inNum = 0;
        ss >> inNum;
        if (!ss.fail())
        {
            //is int
            if (inNum >= 0 && inNum <= handSize() && matchArr.at(inNum))
                return inNum;
        }
        else
        {
            //not int
            ss.clear();
            ss << s;
            ss >> inC;
        }
        if (inC == 'd' || inC == 'D')
        {
            drawCard(uno.drawPile);
            cout << "Drawn " + hand.back()->toString() << endl;
            return hand.back()->match(uno.discardPile->top()) ? handSize() - 1 : DRAWN;
        }
        else
            cout << "Invalid option! " << endl;
        
    }
}
