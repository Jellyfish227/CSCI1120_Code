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
    // TODO: //done, REMOVE after test
    // Show the hand of cards with selectable indexes
    // For each card in hand, print the card's string representation
    // with "[i]"" in front of it, where i is the index of the card
    // in the player's hand vector.
    // If the card cannot match the top of the discard pile, show 
    // "[x]" which means the card cannot be played.
    // Print at most 10 cards per line if there are many cards in hand.
    bool haveMatch = false;
    int counter = 0;
    vector<bool> matchArr(handSize(), false);
    for (int i = 0; i < handSize(); i++)
    {
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



    // You may make an early return with PASSED if no matched cards in hand 
    // and draw pile is empty.
    if (!haveMatch && uno.drawPile->size() == 0) 
        return PASSED;
    
    // Get user input for the option (selected card index or 'D' for draw).
    // Keep prompting until the option is valid.
    // If the input is 'D' (case-insensitive), draw 1 card from draw pile 
    // into this player's hand vector. The drawn card is added to the back
    // of the vector. 
    // If the drawn card is playable, return its index. Otherwise, return 
    // the constant DRAWN to mean a card has been drawn but not playable.
    // The caller seeing DRAWN returned should skip playing any card.
    // If the input is an integer that can index a playable card in hand, 
    // return the integer.
    //
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
            if (inNum >= 0 && inNum <= handSize() && matchArr.at(inNum))
                return inNum;
        }
        else
        {
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
    // Print error message "Invalid option!" for invalid index or incorrect 
    // input.
    //
    // Hint: read the user input as a string first. You can convert it to
    // integer later using an input string stream or the stoi() function.
    // The string stream method is preferred as it can detect non-integer input.
}
