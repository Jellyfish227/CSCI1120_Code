#include <iostream>
#include "Player.h"

#include <algorithm>

using namespace std;

int Player::count = 0; 

Player::Player() {
    count++;
    name = "Player " + to_string(count);
}

string Player::getName() const {
    return name;
}

void Player::setName(string name_) {
    name = name_;
}

int Player::drawCard(DrawPile* drawPile, int n) {
    int d = drawPile->draw(hand, n);
    if (d == 0) {
        cout << "No more cards on draw pile!" << endl;
    }
    else {
        cout << name << " drawn " << d << " card(s)." << endl;
    }
    return d;
}

void Player::printHand(bool flipped) {
    // TODO: //done, REMOVE after test
    // Print all cards in the player's hand in one line.
    // If flipped is true, print the front of each card, e.g. [R1], [GS], [WD]
    // Otherwise, print the back of each card, i.e., "[Uno]".

    for (Card *c : hand) 
    {
        if (flipped) 
            cout << c->toString();
        else 
            cout << "[Uno]";
        if (c != hand.back()) cout << " ";
    }
    cout << endl;
}

int Player::handSize() const {
    return int(hand.size());
}

int Player::handPoints() const {
    // TODO: //done, REMOVE after test
    // Compute and return the sum of values of all cards in hand 
    int sum = 0;
    for (Card *c : hand) {
        sum += (int)c->getValue();
    }
    return sum;
}

void Player::playCard(int idx, GameState& uno) {
    // TODO: //done, REMOVE after test
    // Locate the card at index idx and play it, 
    // i.e. call its play() function
    Card *card = hand.at(idx);
    card->play(uno);

    // Move the card from hand to discard pile
    uno.discardPile->stack(card);
    hand.erase(hand.begin() + idx);
}

Color Player::mostFrequentColor() {
    // TODO: //done, REMOVE after test
    // Return the color that appears most frequently in the hand.
    // Exclude wild (draw 4) cards in this search.
    // If more than one color are equally most frequent, select the color
    // to return in this order: Red, Yellow, Green, Blue.
    int count[4] = {0,0,0,0};
    for (Card *c : hand)
        count[(int)c->getColor()]++;
    int idx = max_element(count, count + 4) - count;
    
    return Color(idx);
}
