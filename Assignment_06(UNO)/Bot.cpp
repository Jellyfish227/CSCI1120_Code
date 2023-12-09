// TODO: //done, REMOVE after test
// Implement the Bot class
#include <iostream>
#include "Bot.h"

using namespace std;

Bot::Bot() : Player(){
    setName(getName() + " (Bot)");
}

int Bot::pickCard(GameState &uno){
    printHand();
    for (int i = 0; i < handSize(); i++)
    {
        if (hand.at(i)->match(uno.discardPile->top()))
            return i; 
    }

    if (uno.drawPile->size() != 0)
    {
        uno.drawPile->draw(hand);
        if (uno.debugMode)
            cout << "Drawn [" + hand.at(hand.size() - 1)->toString() + "]" << endl;
        if (hand.back() == uno.discardPile->top())
            return handSize() - 1;
        return DRAWN;
    } else
        return PASSED;
}
// For the pickCard method, perform the following:
// (1) show the hand in a hidden manner, i.e., print each card as [Uno], 
//     if debugMode is false. 
// (2) Pick the first card in hand, from left to right, that matches 
//     the top card of the discard pile. Return its index in hand.
// (3) If no playable card in hand, draw a card if draw pile still has cards.
// (4) Set the index to return to be the index of the last element in hand.
// (5) If debugMode in client side is true, print "Drawn [XX]" where [XX] is
//     the card drawn.
// (6) If the card drawn matches the discard pile's top, return the drawn 
//     card's index (last element in hand).
//     Otherwise, return the constant DRAWN.
