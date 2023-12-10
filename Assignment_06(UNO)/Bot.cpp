// Name:       Yu Ching Hei
// Student ID: 1155193237
// Email:      chyu@link.cuhk.edu.hk

#include <iostream>
#include "Bot.h"

using namespace std;

Bot::Bot() : Player(){
    setName(getName() + " (Bot)");
}

int Bot::pickCard(GameState &uno){
    printHand(uno.debugMode);
    for (int i = 0; i < handSize(); i++)
    {
        if (hand.at(i)->match(uno.discardPile->top()))
            return i; 
    }

    if (uno.drawPile->size() != 0)
    {
        drawCard(uno.drawPile);
        if (uno.debugMode)
            cout << "Drawn " + hand.back()->toString() << endl;
        if (hand.back()->match(uno.discardPile->top()))
            return handSize() - 1;
        return DRAWN;
    } else
        return PASSED;
}
